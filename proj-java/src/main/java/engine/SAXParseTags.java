package engine;

/**
 * Parse ao dump de tags.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180610
 */

import org.xml.sax.helpers.*;
import org.xml.sax.*;

public class SAXParseTags extends DefaultHandler {

    private TCD_Community com;

    /**
     * Contrutor parametrizado.
     * 
     * @param com - Estrutura de dados TCD_Community. 
     */
    public SAXParseTags(TCD_Community com) {
        super();
        this.com = com;
    }

    /**
     * Função que extrai os elementos necessários das tags para preencher a
     * respetiva estrutura de dados.
     * @param namespaceURI - String usada para identificar um recurso na Internet.
     * @param localName - Nome do elemento.
     * @param qName - Combinação do namespace com o nome do elemento.
     * @param atts -  Lista de atributos de um elemento.
     * 
     * @throws SAXException
     */
    public void startElement(String namespaceURI,
                            String localName,
                            String qName,
                            Attributes atts) throws SAXException {
                                
        int length = atts.getLength(); //retorna o tamanho da lista de atributos                            
        
        int id, tagname;
        id = tagname = 0;
        
        for (int i = 0; i < length; i++) {
            String name = atts.getQName(i); //retorna o nome do elemento
            
            if(name.equals("Id"))
                id = i;
                
            else if (name.equals("TagName"))
                tagname = i;                
        }

        if (length != 0){
            long tag_id = Long.parseLong(atts.getValue(id));
            String tag_name = atts.getValue(tagname);
            
            com.insertTag(tag_name, tag_id);
        }
    }
}