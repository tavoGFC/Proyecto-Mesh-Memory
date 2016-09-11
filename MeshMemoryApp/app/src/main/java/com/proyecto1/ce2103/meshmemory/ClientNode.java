package com.proyecto1.ce2103.meshmemory;

import android.support.v7.app.AppCompatActivity;
import android.util.Log;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * Created by Ricardo on 09/09/16.
 */
public class ClientNode extends AppCompatActivity{

    Node node;
    String mensaje;
    public Socket socket;
    protected DataOutputStream salida;
    protected BufferedReader entrada;
    String respuestaEntrada;


    /**
     * El constructor asigna el ip de la maquina que va a ser utilizada como servidor
     */
    public ClientNode(final String ipServidor, final int portSevidor) {

        Thread thread = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                try
                {
                    socket = new Socket(ipServidor, portSevidor);
                    System.out.print("Se inicio el cliente");

                    entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    salida = new DataOutputStream(socket.getOutputStream());

                    comunicarse();

                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
            }
        });
        thread.start();

    }


    /**
     * Envia un mensaje al servidor
     * @throws InterruptedException
     */
    public void comunicarse() throws InterruptedException{
        Thread thread = new Thread(new Runnable()
        {

            @Override
            public void run()
            {
                try {
                    salida.writeUTF(mensaje);
                    respuestaEntrada = entrada.readLine();
                    Log.d(this.toString(), "Servidor respondió : " + respuestaEntrada);
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
