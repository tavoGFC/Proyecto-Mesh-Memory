package com.proyecto1.ce2103.meshmemory;

import android.util.Log;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * Created by gustavo on 09/09/16.
 */
public class ServerBranch extends Thread {

    private Socket socketCliente;
    private DataOutputStream salida;
    private BufferedReader entrada;
    private ServerManager superservidor;


    /**
     * constructor de la clase.
     * inicializa los atributos asignados
     *
     * @param socket
     * @param superservidor
     * @throws IOException
     */
    public ServerBranch(Socket socket,ServerManager superservidor) throws IOException {
        this.superservidor=superservidor;
        this.socketCliente = socket;
        salida = new DataOutputStream(socketCliente.getOutputStream());
        entrada = new BufferedReader(new InputStreamReader(socketCliente.getInputStream()));
    }

    /**
     * Cierra la entrada, la salida y el socket con el cliente
     */
    public void desconectar() {
        try {
            System.out.println("Cliente:  "+socketCliente+"  desconectado");
            entrada.close();
            salida.close();
            socketCliente.close();
        } catch (IOException ex) {
            System.out.println("Errror al desconectar el cliente "+socketCliente);
        }
    }

    /**
     * envia un mensaje al cliente asociado con el socket
     * @param mensaje
     */
    public void enviarAcliente(String mensaje){
        try {
            salida.writeUTF(mensaje);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    @Override
    /**
     *  espera a que el cliente envie un mensaje, este mensaje es descifrado y le responde al cliente
     * 	con un string, el cual contiene las instrucciones que debe realizar el cliente
     *
     */
    public void run() {
        while(true){
            try {

                String mensajeEntrada = entrada.readLine();
                Log.d(this.toString(), "El mensaje recibido en el servidor es: " + mensajeEntrada);
                salida.writeUTF("Conexion establecida" );

            }
            catch (IOException ex) {
                ex.printStackTrace();
            }

        }
    }

}