package xmlToJson;


import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;


public class pruebas {

	public static void main(String[] args) throws TransformerConfigurationException, TransformerException {
		
		
		XMLDispositivos a=new XMLDispositivos("dispositivos");
		
		//a.añadirDispositivos("maria", "2783", "erfer", "vrtgrg", "vfrfr", "frr", "frtgrg");
	
		
		String f = "fer-2783-erfervrtgrg-vfrfrf-rr-frtgrg";
		
		XMLDispositivos a1 = new XMLDispositivos("dispositivos");
		
//		jsonParser m = new jsonParser();
//		m.parser("dispositivos");
		
		convertidorJson s = new convertidorJson();
		
		s.convertir("/home/fernanda/workspace/xmlTojson/dispositivos.xml");
		
		//separador s = new separador();
		
		//listaDoble l = s.separar(f);
		//s.separar(f);
		//l.imprimir();
		a1.añadirDispositivos("fer",f);
		
		
	}

}


