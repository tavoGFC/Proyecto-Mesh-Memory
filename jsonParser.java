package xmlToJson;

import java.io.FileReader;
import java.util.Iterator;
 
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

public class jsonParser {
	
	public static void parser(String nombre){
		
		JSONParser parser = new JSONParser();
		
		try {
			 
            Object obj = parser.parse(new FileReader("/home/fernanda/workspace/xmlTojson/dispositivos.json"));
 
            JSONObject jsonObject = (JSONObject) obj;
 
            //String name = (String) jsonObject.get("dispositivos");
            nombre = jsonObject.toJSONString();
            //JSONArray companyList = (JSONArray) jsonObject.get("Company List");
 
            System.out.println(nombre);
            //System.out.println("Author: " + author);
//            System.out.println("\nCompany List:");
//            Iterator<String> iterator = companyList.iterator();
//            while (iterator.hasNext()) {
//                System.out.println(iterator.next());
//            }
 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
		
	}


