package com.proyecto1.ce2103.meshmemory;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class Principal extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_principal);
    }


    public void onClickIniciar(View view){
        Intent i = new Intent(this, Manager.class);
        startActivity(i);
    }

    public void onClickNode(View view){
        Intent i = new Intent(this, Node.class );
        startActivity(i);
    }

    @Override
    public void onBackPressed() {
        Log.d("Principal", "onBackPressed Called");

    }


}
