
/**
 * Escreva a descrição da classe Users aqui.
 * 
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.util.List;

public class Users {
  private long user_id;
  private String shortbio;
  private String username;
  private int reputation;
  private int n_posts;
  private List<Posts> posts;
  
  /**
     * Função que devolve o id do utilizador.
     *
     * @returns long - Identificador do user.
     */
  public long getUsersId() {
      return user_id;
    }
 
  /**
     * Função que estabelece o id do utilizador.
     *
     * @param long - Id do user.
     */
  public void setUserId(long user_id) {
      this.user_id = user_id;
  }
 
  /**
     * Função que devolve o nome do utilizador.
     *
     * @returns String - Nome do user.
     */
  public String getUserName() {
      return username;
    }
    
  /**
     * Função que estabelece o nome do utilizador.
     *
     * @param String - Nome do user.
     */
  public void setUserName(String username) {
      this.username = username;
    }
  
  /**
     * Função que devolve a biografia do utilizador.
     *
     * @returns String - Biografia do user.
     */
  public String getUserBio() {
      return shortbio;
    }
  
  /**
     * Função que estabelece a biografia do utilizador.
     *
     * @param String - Biografia do user.
     */
  public void setUserBio(String shortbio) {
      this.shortbio = shortbio;
    }
  
  /**
     * Função que devolve a reputação do utilizador.
     *
     * @returns int - Reputação do user.
     */
  public int getReputation() {
      return reputation;
    }  
 
  /**
     * Função que estabelece a reputação do utilizador.
     *
     * @param int - Reputação do user.
     */
  public void setReputation(int reputation) {
      this.reputation = reputation;
    }
  
  /**
     * Função que devolve o número de posts do utilizador.
     *
     * @returns int - Númerod e posts do user.
     */
  public int getNPosts() {
      return n_posts;
    }   
    
    public Users clone() {
        return this;
    }
}
