package xmlToJson;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;

import org.json.JSONObject;
import org.json.XML;

public class convertidorJson {

	/***
	 * Funcion que convierte un archivo xml a formato json
	 * @param nombre dirección del archivo xml 
	 */
	public void convertir(String nombre){
		
		
	/**
	 * varia con el nombre del archivo que va a salir en formato json
	 */
	String fileName = "dispositivos.json";
	
    try  
    {  

    	/***
    	 * en esta parte abre y lee el xml, empieza a convertir todo para
    	 * luego guardar la informacion en un archivo formato json
    	 */
        File file = new File (nombre);  
        InputStream inputStream = new FileInputStream(file);  
        StringBuilder builder =  new StringBuilder();  
        int ptr = 0;  
        while ((ptr = inputStream.read()) != -1 )  
        {  
            builder.append((char) ptr); 
        }  

        String xml  = builder.toString();  
        JSONObject jsonObj = XML.toJSONObject(xml);   
        FileWriter fileWriter = new FileWriter(fileName);

    
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        for(int i= 0 ;i < jsonObj.toString().split(",").length; i ++) {
           System.out.println(jsonObj.toString().split(",")[i]);
           bufferedWriter.write(jsonObj.toString().split(",")[i]);
           bufferedWriter.write("\n");
        }

        bufferedWriter.close();
        
    }
    
      catch(IOException ex) {
            System.out.println(
                "Error writing to file '"
                + fileName + "'");
        }catch(Exception e)  
        {  
            e.printStackTrace();  
        }
}
}  


