
/**
 * Escreva a descrição da classe Users aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import java.util.List;

public class Users
{
    
  private long user_id;
  private String shortbio;
  private String username;
  private int reputation;
  private int n_posts;
  private List<Posts> posts;
    
  
    public void incrementaNPosts() {
         n_posts = n_posts + 1;
    }
    
    public Users clone() {
        return this;
    }
}
