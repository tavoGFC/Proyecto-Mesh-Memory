package xmlToJson;

/**
 * 
 * @author Fernanda
 *
 */

	import javax.xml.transform.TransformerConfigurationException;
	import javax.xml.transform.TransformerException;

import org.json.simple.JSONObject;
import org.w3c.dom.Document;
	import org.w3c.dom.Element;
	import org.w3c.dom.Node;
	import org.w3c.dom.Text;

	public class XMLDispositivos extends XML {
		
		Document documento;
		Element raiz;
		
		/**
		 * esta funcion se encarga de crear un XML que almacena
		 * los datos del dispositivo
		 * @param name
		 */
		
		public XMLDispositivos(String nombreXML) {
			super(nombreXML);
			//Obtenemos la referencia al documento que queremos modificar
			this.documento = super.documento;
			
			//Obtiene el elemento raíz del documento
			this.raiz = super.raiz; 
		}
		
		/**
		 * Funcion que añade un dispositivo nuevo al xml
		 * @param dispNuevo
		 * @param nuevoId
		 * @param nuevoIp
		 * @param nuevoPuert
		 * @param nuevoNum
		 * @param nuevoBytTot
		 * @param nuevoBytUs
		 * @throws TransformerConfigurationException
		 * @throws TransformerException
		 */
		
		//String id, String ip, String puerto, String num, String bytTot, String bytUs 
		
		public void añadirDispositivos(String dispNuevo,String infoDisp ) throws TransformerConfigurationException, TransformerException{
			//Creamos los elementos a añadir
			Element disposivitos =documento.createElement(dispNuevo);
			Text id=documento.createTextNode(infoDisp);
//			Text nInfo=documento.createTextNode(infoDisp);
			
//			//Añadimos los elementos creados
//			id.appendChild(nId);
			disposivitos.appendChild(id);
			
			
			raiz.appendChild(disposivitos);
			//"Cerramos" el xml
			cerrarXML();
		}

	}
	

