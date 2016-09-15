package xmlToJson;


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
		 * la contraseña y el nombre del cada jugador
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
		 * funcion que crea y mete en el XML los usuarios del juego
		 * @param nombreNuevo
		 * @param contraseñaNueva
		 * @throws TransformerConfigurationException
		 * @throws TransformerException
		 */
		
		//String id, String ip, String puerto, String num, String bytTot, String bytUs 
		
		public void añadirDispositivos(String dispNuevo, String nuevoId, String nuevoIp, String nuevoPuert, String nuevoNum, String nuevoBytTot, String nuevoBytUs ) throws TransformerConfigurationException, TransformerException{
			//Creamos los elementos a añadir
			Element disposivitos =documento.createElement(dispNuevo);
			Element id=documento.createElement("id");
			Text nId=documento.createTextNode(nuevoId);
			
			Element ip=documento.createElement("ip");
			Text nIp=documento.createTextNode(nuevoIp);

			Element puerto=documento.createElement("puerto");
			Text nPuert=documento.createTextNode(nuevoPuert);
			
			Element num=documento.createElement("numero");
			Text nNum=documento.createTextNode(nuevoNum);
			
			Element bytTot=documento.createElement("bytesTotales");
			Text nBytTot=documento.createTextNode(nuevoId);
			
			Element bytUs=documento.createElement("bytesTotales");
			Text nBytUs=documento.createTextNode(nuevoId);
			
			//Añadimos los elementos creados
			id.appendChild(nId);
			disposivitos.appendChild(id);
			
			ip.appendChild(nIp);
			disposivitos.appendChild(ip);
			
			puerto.appendChild(nPuert);
			disposivitos.appendChild(puerto);
			
			num.appendChild(nNum);
			disposivitos.appendChild(num);
			
			bytTot.appendChild(nBytTot);
			disposivitos.appendChild(bytTot);
			
			bytUs.appendChild(nBytUs);
			disposivitos.appendChild(bytUs);
			
			raiz.appendChild(disposivitos);
			//"Cerramos" el xml
			cerrarXML();
		}

	}
	

