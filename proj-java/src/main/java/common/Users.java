package common;

/**
 * Classe que define um utilizador.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Users {
    private long user_id;
    private String shortbio;
    private String username;
    private int reputation;
    private int n_posts;
    private List<Posts> posts;

    /**
     * Construtor por omissão de Users.
     */
    public Users() {
        this.user_id = 0;
        this.shortbio = "";
        this.username = "";
        this.reputation = 0;
        this.n_posts = 0;
        this.posts = new ArrayList<>();
    }

    /**
     * Construtor parametrizado de Users.
     *
     * @param user_id Identificador do user
     * @param shortbio Biografia do user
     * @param username Nome do user
     * @param reputation Reputação do user
     * @param n_posts Número de posts do user
     * @param posts Lista de posts do user
     */
    public Users(long user_id, String shortbio, String username,
                int reputation, int n_posts, List<Posts> posts) {
        this.user_id = user_id;
        this.shortbio = shortbio;
        this.username = username;
        this.reputation = reputation;
        this.n_posts = n_posts;
        setPosts(posts);
    }

    /**
     * Construtor de Cópia.
     *
     * @param u User a ser replicado
     */
    public Users(Users u) {
        this.user_id = u.getUsersId();
        this.shortbio = u.getUserBio() ;
        this.username = u.getUserName();
        this.reputation = u.getReputation();
        this.n_posts = u.getNPosts();
        this.posts = u.getPosts();
    }

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
     * @param user_id - Id do user.
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
     * @param username - Nome do user.
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
     * @param shortbio - Biografia do user.
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
     * @param reputation - Reputação do user.
     */
    public void setReputation(int reputation) {
        this.reputation = reputation;
    }

    /**
     * Função que devolve o número de posts do utilizador (question e answer).
     *
     * @returns int - Número de posts do user.
     */
    public int getNPosts() {
        return n_posts;
    }

    /**
     * Função que estabelece o numero de posts do utilizador.
     *
     * @param n_posts - Numero de posts do user.
     */
    public void setNPosts(int n_posts) {
        this.n_posts = n_posts;
    }

    /**
     * Função que devolve o conjunto de posts do utilizador.
     *
     * @return List<Posts> - Lista de posts do user.
     */
    public List<Posts> getPosts() {
        return posts
                .stream()
                .map(Posts::clone)
                .collect(Collectors.toList());
    }

    /**
     * Função que estabelece o conjunto de posts do utilizador.
     *
     * @param posts - Lista de posts do user.
     */
    public void setPosts(List<Posts> posts) {
        this.posts = posts
                .stream()
                .map(Posts::clone)
                .collect(Collectors.toList());
    }

    /**
     * Função que incrementa o numero de posts do utilizador.
     *
     */
    public void incrementaNPosts() {
        n_posts = n_posts + 1;
    }

    /**
     * Método que determina se dois users são iguais.
     *
     * @param object Objecto a ser usado como termo de comparação.
     *
     * @return Boolean indicando se os dois objetos são iguais
     */
    public boolean equals(Object object) {
        if(this == object)
            return true;

        if(object == null || (this.getClass() != object.getClass()))
            return false;


        Users u = (Users) object;
        return  (user_id == u.getUsersId() && shortbio.equals(u.getUserBio())
                 && reputation == u.getReputation() && n_posts == u.getNPosts()
                 && posts.equals(u.getPosts()));
    }

    /**
     * Método que devolve a representação em String de Users.
     *
     * @return String que representa um user.
     */
    public String toString() {
       StringBuilder PostsList = new StringBuilder();

            for (Posts p: posts) {
                 PostsList.append(p.toString());
                 PostsList.append(" ");
            }

        return "Users{" +
                ", UserId = " + user_id +
                ", ShortBio = " + shortbio +
                ", Username = " + username +
                ", Reputation = " + reputation +
                ", Number of Posts = " + n_posts +
                ", Posts =" + PostsList.toString() +
                '}';
    }

    /**
     * Método que faz uma cópia de Users.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de Users
     */
    public Users clone() {
        return new Users(this);
    }
    
    /**
     * Método adiciona um post ao utilizador.
     *
     * @param e Post
     */
    public void addPost(Posts e) {
        posts.add(e.clone());
    }
}
