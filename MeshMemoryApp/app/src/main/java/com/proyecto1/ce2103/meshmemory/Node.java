package com.proyecto1.ce2103.meshmemory;

import android.content.Context;
import android.content.DialogInterface;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.provider.Settings;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.telephony.TelephonyManager;
import android.text.format.Formatter;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class Node extends AppCompatActivity {


    //parametros que el usuario ingresa
    TextView ipHostMMManager, portMMManager, phoneNumberT;
    GridLayout frameLParameters;
    String ipHostMMM, portMMM;
    //parametros que se obtienen desde el telefono
    String idDevice, ipAddress, phoneNumber;
    TelephonyManager telephoneM;


    //Mensaje recivido del servidor
    TextView readMensajeOfManager;

    ClientNode clientNode;

    Button buttonSendParameter;


    //mensaje a enviar
    String parametros;




    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_node);
        ingresarParametros();

        //id device ClientNode
        idDevice = Settings.Secure.getString(this.getContentResolver(), Settings.Secure.ANDROID_ID);
        //ip device ClienNode
        WifiManager wifiMgr = (WifiManager) getSystemService(WIFI_SERVICE);
        ipAddress = Formatter.formatIpAddress(wifiMgr.getConnectionInfo().getIpAddress());
        //phone device ClientNode
        telephoneM = (TelephonyManager) getSystemService(Context.TELEPHONY_SERVICE);
        phoneNumber = telephoneM.getLine1Number();

        //mostrar mensaje enviado por el manager
        readMensajeOfManager = (TextView) findViewById(R.id.textViewResponseManager);

        buttonSendParameter = (Button) findViewById(R.id.buttonEnviarparametros);

    }




    @Override
    public void onBackPressed() {
        AlertDialog.Builder aletExitApp = new AlertDialog.Builder(this);

        aletExitApp.setTitle("Close");
        aletExitApp.setMessage("Desea cerrar la aplicacion");

        aletExitApp.setPositiveButton("Si", new DialogInterface.OnClickListener(){
            @Override
            public void onClick(DialogInterface dialog, int which) {
                finishAffinity();
                System.exit(0);

            }
        });

        aletExitApp.setNegativeButton("No", new DialogInterface.OnClickListener(){
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        });

        aletExitApp.show();
    }

    public void ingresarParametros(){
        frameLParameters = (GridLayout) findViewById(R.id.frameParametros);
        frameLParameters.setEnabled(true);
        frameLParameters.setVisibility(View.VISIBLE);

        ipHostMMManager = (TextView)findViewById(R.id.editTextIPMMManger);
        portMMManager   = (TextView)findViewById(R.id.editTextPortMMManager);
        phoneNumberT    = (TextView)findViewById(R.id.editTextPhoneNumber);

    }

    public void onClickSendParameter(View view) {
        ipHostMMM = ipHostMMManager.getText().toString();
        portMMM = portMMManager.getText().toString();
        phoneNumber = phoneNumberT.getText().toString();

        if (ipHostMMM.isEmpty() || portMMM.isEmpty()) {
            AlertDialog.Builder alertError = new AlertDialog.Builder(this);

            alertError.setTitle("Error");
            alertError.setMessage("Falta uno o mas parametros");

            alertError.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();

                }
            });

            alertError.show();

        } else {
            if (phoneNumber.isEmpty()) {
                AlertDialog.Builder phoneFail = new AlertDialog.Builder(this);

                phoneFail.setTitle("Numero Telefonico");
                phoneFail.setMessage("Ingrese el numero Telefonico");

                phoneFail.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.cancel();
                        phoneNumberT.setVisibility(View.VISIBLE);
                    }
                });

                phoneFail.show();
            }else {
                frameLParameters.setEnabled(false);
                frameLParameters.setVisibility(View.INVISIBLE);
                Log.d(this.toString(), "Se envio los parametros: " + ipHostMMM
                        + ", " + portMMM + ", " + idDevice + ", " + ipAddress + ", " + phoneNumber);

                parametros = " ID: " + idDevice +  " IP: " + ipAddress + " Phone Number: " + phoneNumber + "\n";

                clientNode = new ClientNode(ipHostMMM, Integer.parseInt(portMMM));
                clientNode.mensaje = parametros;
                //readMensajeOfManager.setText(clientNode.respuestaEntrada);
                System.out.print(clientNode.respuestaEntrada);
            }
        }

    }


}