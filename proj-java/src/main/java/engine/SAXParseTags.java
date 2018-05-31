package engine;


/**
 * Parse ao dump de tags.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
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