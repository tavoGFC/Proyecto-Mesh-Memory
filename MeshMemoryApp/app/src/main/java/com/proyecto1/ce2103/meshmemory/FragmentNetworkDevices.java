package com.proyecto1.ce2103.meshmemory;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ExpandableListView;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


/**
 * A simple {@link Fragment} subclass.
 */
public class FragmentNetworkDevices extends Fragment {

    //Lista de dispositivos

    com.proyecto1.ce2103.meshmemory.ExpandableListAdapter listAdapter;
    ExpandableListView expListView;
    List<String> listDataHeader;
    HashMap<String, List<String>> listDataChild;

    public FragmentNetworkDevices() {
        // Required empty public constructor
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_network_devices, container, false);

        //get ListViewExp
        expListView = (ExpandableListView)view.findViewById(R.id.listExp);

        //preparing list data
        prepareListData();
        listAdapter = new com.proyecto1.ce2103.meshmemory.ExpandableListAdapter(this.getContext(),listDataHeader,listDataChild);

        //seting list adapter
        expListView.setAdapter(listAdapter);
        return view;
    }


    /*
    * Preparing the list data
    */
    private void prepareListData() {
        listDataHeader = new ArrayList<String>();
        listDataChild = new HashMap<String, List<String>>();

        // Adding child data
        listDataHeader.add("Prueba");
        listDataHeader.add("Prueba1");

        // Adding child data
        List<String> Prueba = new ArrayList<String>();
        Prueba.add("ID:234234");
        Prueba.add("IP:3.3.3");
        Prueba.add("Phone Number: 32342343");
        Prueba.add("Port: 434");
        Prueba.add("Bytes: 23");


        List<String> Prueba1 = new ArrayList<String>();
        Prueba1.add("ID:67567");
        Prueba1.add("IP:6.5.4");
        Prueba1.add("Phone Number: 89784353");
        Prueba1.add("Port: 565");
        Prueba1.add("Bytes: 75");


        listDataChild.put(listDataHeader.get(0), Prueba); // Header, Child data
        listDataChild.put(listDataHeader.get(1), Prueba1);
    }


}
