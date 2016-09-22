package xmlToJson;


import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;


public class pruebas {

	public static void main(String[] args) throws TransformerConfigurationException, TransformerException {
		
		
		XMLDispositivos a = new XMLDispositivos("dispositivos");
		
		separador s = new separador();
				
		String f = "fer-2783-erfervrtgrg-vfrfrf";
		String j = "{dispositivos:{fer:fer-2783-erfervrtgrg-vfrfrf-rr-frtgrg";
		
		
		
//		jsonParser m = new jsonParser();
//		m.parser("dispositivos");
		
		convertidorJson m = new convertidorJson();
		
		
		
		//separador s = new separador();
		
		listaDoble l = s.separar(j);
		s.separar(j);
		//l.imprimir();
		a.añadirDispositivos("fer",f);
		m.convertir("dispositivos.xml");
		//System.out.println(a.getDir());
		
		//m.convertir(a.getDir());
		
		
	
		
	}

}


