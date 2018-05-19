
/**
 * Escreva a descrição da classe SAXParseTags aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
import org.xml.sax.helpers.*;
import org.xml.sax.*;

public class SAXParseTags extends DefaultHandler {

    private TCD_Community com;
    
        public SAXParseTags(TCD_Community com) {
            super();
            this.com = com;
        }
        
        
    public void startElement(String namespaceURI,
                             String localName,
                             String qName, 
                             Attributes atts) throws SAXException {
                                 
    }  
}