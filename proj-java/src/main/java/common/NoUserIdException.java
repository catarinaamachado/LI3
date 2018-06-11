package common;

/**
 * Classe de exceção que é lançada quando o id passado como parametro
 * não identifica nenhum user.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180611
 */

public class NoUserIdException extends Exception {

    /**
     * Contrutor vazio da classe.
     */
    public NoUserIdException(){
        super();
    }

    /**
     * Contrutor parametrizado da classe.
     * @param s  - Mensagem de erro.
     */
    public NoUserIdException(String s) {
        super(s);
    }
}
