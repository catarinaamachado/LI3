package common;

/**
 * Classe de exceção que é lançada quando o id passado como parametro
 * não identifica nenhum post, ou seja, nem uma pergunta nem uma resposta.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180607
 */

public class NoPostIdException extends Exception {
   
    /**
     * Contrutor vazio da classe.
     */
    public NoPostIdException(){
        super();
    }
    
    /**
     * Contrutor parametrizado da classe.
     * @param s  - Mensagem de erro.
     */
    public NoPostIdException(String s) {
        super(s);
    }
}
