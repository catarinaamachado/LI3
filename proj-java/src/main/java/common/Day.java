package common;

/**
 * Estrutura de dados relativa aos dias.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180609
 */

import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class Day {
    private int day;
    private int month;
    private int year;
    private int n_questions;
    private int n_answers;
    private List<Question> questions; 
    private List<Answer> answers; 

    /**
     * Construtor por omissão de Day.
     */
    public Day() {
        this.day = 0;
        this.month = 0;
        this.year = 0;
        this.n_questions = 0;
        this.n_answers = 0;
        this.questions = new ArrayList();
        this.answers = new ArrayList();
    }
    
    /**
     * Construtor parametrizado de Day.
     *
     * @param post_id Identificador do post
     * @param user_id Identificador do user
     * @param title Título da pergunta
     * @param tags Tags da pergunta
     * @param n_questions Número de perguntas
     * @param n_answers Número de respostas
     * @param questions Perguntas do dia
     * @param answers Respostas do dia
     */
    public Day(int day, int month, int year, int n_questions, 
                    int n_answers, List questions, List answers) {
        this.day = day;
        this.month = month;
        this.year = year;
        this.n_questions = n_questions;
        this.n_answers = n_answers;
        setQuestions(questions);
        setAnswers(answers);
      }

    /**
     * Construtor de Cópia.
     *
     * @param d Dia 
     */
    public Day(Day d) {
        this.day = d.getDay();
        this.month = d.getMonth();
        this.year = d.getYear();
        this.n_questions = d.getN_questions();
        this.n_answers = d.getN_answers();
        this.questions = d.getQuestions();
        this.answers = d.getAnswers();
    }
    
    /**
     * Método que devolve o dia (número) da data.
     *
     * @returns int - dia.
     */
    public int getDay() {
        return this.day;
    }
    
    /**
     * Método que estabelece o dia da data.
     *
     * @param int Dia.
     */
    public void setDay(int day) {
        this.day = day;
    }
    
    /**
     * Método que devolve o mês da data.
     *
     * @returns int - mês.
     */
    public int getMonth() {
        return this.month;
    }
 
    /**
     * Método que estabelece o mês da data.
     *
     * @param int Mês.
     */
    public void setMonth(int month) {
        this.month = month;
    }
    
    /**
     * Método que devolve o ano da data.
     *
     * @returns int - ano.
     */
    public int getYear() {
        return this.year;
    }
    
    /**
     * Método que estabelece o ano da data.
     *
     * @param int Ano.
     */
    public void setYear(int year) {
        this.year = year;
    }
    
    /**
     * Método que devolve o número de perguntas
     * efetuadas na data.
     *
     * @returns int - número de perguntas.
     */
    public int getN_questions() {
        return this.n_questions;
    }    

    /**
     * Método que estabelece o número de perguntas da data.
     *
     * @param int número de perguntas.
     */
    public void setN_questions(int n_questions) {
        this.n_questions = n_questions;
    }
        
    /**
     * Método que devolve o número de respostas
     * efetuadas na data.
     *
     * @returns int - número de respostas.
     */
    public int getN_answers() {
        return this.n_answers;
    }

    /**
     * Método que estabelece o número de respostas da data.
     *
     * @param int número de respostas.
     */
    public void setN_answers(int n_answers) {
        this.n_answers = n_answers;
    }
    
    /**
     * Método que devolve as perguntas da data.
     *
     * @returns List<Question> - lista das perguntas.
     */
    public List<Question> getQuestions() {
        return questions.stream().map(Question :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }
    
    /**
     * Função que estabelece as perguntas feitos num determinado dia.
     *
     * @param perguntas Lista com as perguntas.
     */
    public void setQuestions(List<Question> perguntas) {
        this.questions = perguntas.stream().map(Question :: clone).
                        collect(Collectors.toCollection(ArrayList::new));
    }  
        
    /**
     * Método que devolve as respostas da data.
     *
     * @returns List<Answer> - lista das respostas.
     */
    public List<Answer> getAnswers() {
        return answers.stream().map(Answer :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }
  
    /**
     * Função que estabelece as respostas feitos num determinado dia.
     *
     * @param respostas Lista com as respostas.
     */
    public void setAnswers(List<Answer> respostas) {
        this.answers = respostas.stream().map(Answer :: clone).
                        collect(Collectors.toCollection(ArrayList::new));
    }

    /**
     * Método que faz uma cópia de day.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de day
     */    
    public Day clone() {
         return new Day(this);
    }    
        
    /**
     * Método que determina se dois dias são iguais.
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

        Day dia = (Day) object;
        return  (day == dia.getDay() && month == dia.getMonth() && year == dia.getYear() && 
                 n_questions == dia.getN_questions() && n_answers == dia.getN_answers() &&
                 questions.equals(dia.getQuestions()) && answers.equals(dia.getAnswers()));
    }    

    /**
     * Método que devolve a representação em String de Day.
     *
     * @return String que representa um dia.
     */
    public String toString() {
        StringBuilder AnswersList = new StringBuilder();
        StringBuilder QuestionsList = new StringBuilder();
        
        for (Answer resposta: answers) {      
            AnswersList.append(resposta.toString());
            AnswersList.append(" "); 
        }  
        
        for (Question pergunta: questions) {      
            AnswersList.append(pergunta.toString());
            AnswersList.append(" "); 
        }  
        
        return "Day {" +
                ", Dia = " + day +
                ", Mês = " + month +
                ", Ano = " + year +
                ", Número de perguntas = " + n_questions +
                ", Número de respostas = " + n_answers +
                ", Questions =" + QuestionsList.toString() +
                ", Answers =" + AnswersList.toString() +
                "}";
    }    
}
