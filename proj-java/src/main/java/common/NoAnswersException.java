package common;


/**
 * Classe de exceção para quando uma pergunta não tem nenhuma resposta
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180607
 */
public class NoAnswersException extends Exception{
    
    /**
     * Contrutor vazio da classe.
     */
    public NoAnswersException(){
        super();
    }
    
    /**
     * Contrutor parametrizado da classe.
     * @param s  - Mensagem de erro.
     */
    public NoAnswersException(String s) {
        super(s);
    }
    
}
