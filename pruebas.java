package xmlToJson;


import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;


public class pruebas {

	public static void main(String[] args) throws TransformerConfigurationException, TransformerException {
		
		
		XMLDispositivos a=new XMLDispositivos("dispositivos");
		a.añadirDispositivos("fer", "2783", "erfer", "vrtgrg", "vfrfr", "frr", "frtgrg");
		a.añadirDispositivos("maria", "2783", "erfer", "vrtgrg", "vfrfr", "frr", "frtgrg");
		
		separador s = new separador();
		
		String f = "fer/maria/reyes";
		
		s.separar(f);
		listaDoble mensaje1separado=s.separar(f);
		;
		mensaje1separado.Imprimir();
		
		
		

	}

}


