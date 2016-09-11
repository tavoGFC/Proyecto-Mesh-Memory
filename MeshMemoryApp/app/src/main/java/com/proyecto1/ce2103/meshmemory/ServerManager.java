package com.proyecto1.ce2103.meshmemory;

import android.util.Log;

import java.io.IOException;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Enumeration;

/**
 * Created by Ricardo on 09/09/16.
 */
public class ServerManager implements Runnable {

    ServerBranch serverBranch;

    ServerSocket socketServidor;
    int portSocketServer = 8080;

    /**
     * Constructor, este inicializa el socketServidor
     */
    public ServerManager(){
        try {
            socketServidor = new ServerSocket(portSocketServer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    @Override
    /**
     * metodo heredado de la clase Runnable por lo que es lo que se va a hacer en un hilo.
     * Este metodo espera a que un cliente se conecte via socket, este socket es enviado a una
     * RamaServidor, cada RamaServidor se encarga de manejar los mensajes de cada cliente asociado
     */
    public void run() {
        Thread thread = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                try
                {
                    while (true) {
                        final Socket clienteSocket = socketServidor.accept();
                        System.out.println("Nueva conexión entrante: " + clienteSocket);
                        serverBranch = new ServerBranch(clienteSocket, ServerManager.this);
                        serverBranch.start();
                    }
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
            }
        });
        thread.start();

    }

}


