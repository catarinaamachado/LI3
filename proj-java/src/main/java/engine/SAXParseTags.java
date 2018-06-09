package engine;

import org.xml.sax.helpers.*;
import org.xml.sax.*;

/**
 * Parse ao dump de tags.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

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
     * Função que extrai os elementos necessários das tags para preencher as
     * respetivas estruturas de dados.
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
    }
}