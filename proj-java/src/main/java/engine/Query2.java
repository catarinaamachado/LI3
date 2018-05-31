package engine;
import common.*;
import java.util.List;
import java.util.Comparator;
import java.util.stream.Collectors;
import java.util.ArrayList;

/**
 * Classe que responde à query2.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180531
 */
public class Query2 {
   TCD_Community com;
   
    /**
     * Construtor parametrizado.
     *
     * @param com Estrutura de dados do TCD_Community
     */
    Query2(TCD_Community com) {
        this.com = com;
    } 
    
    /**
     * Função que devolve o top N utilizadores com maior número
     * de posts de sempre. Para isto, são considerados tanto perguntas
     * quanto respostas dadas pelo respectivo utilizador.
     *
     * @param N Número de utilizadores com mais posts.
     * 
     * @returns List<Long> - lista com os ids dos N utilizadores com mais posts publicados
     */
    public List<Long> run(int N) {
        return com.getMapUsers().values().stream().sorted(Comparator.comparing
               (Users:: getNPosts).reversed()).limit(N).map(u -> u.getUsersId()).
               collect(Collectors.toCollection(ArrayList::new));
    }
}
