package li3;

import common.*;
import engine.TCD_Community;

import org.xml.sax.SAXException;
import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;

import java.time.LocalDate;
import java.time.Month;
import java.util.List;
import java.util.ArrayList;

public class Main {


    public static void main(String[] args) {


        /*
            LOG CONFIGURATION
        */
        MyLog log = new MyLog("results");
        MyLog logtime = new MyLog("times");
        /* -------------------------------------------------------------------------------------------*/

        long before, after;
        TADCommunity qe = new TCD_Community();

        /*
            LOAD PHASE
         */

        boolean loadComplete = false;

        try {
            before = System.currentTimeMillis();
            qe.load(args[0]);
            after = System.currentTimeMillis();
            logtime.writeLog("LOAD -> " + (after - before) + " ms");
            loadComplete = true;
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (SAXException e) {
            System.out.println("SAXException: " + e.getMessage());
        } catch (ParserConfigurationException e) {
            System.out.println("ParserConfigurationException: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IOException: " + e.getMessage());
        }

        //verifica se o load foi completado com sucesso
        if (!loadComplete) {
            return;
        }

        /*
           Query 1
        */
        before = System.currentTimeMillis();
        Pair<String, String> q1 = new Pair<>("null", "null");
        try {
            q1 = qe.infoFromPost(801049);
            //System.out.println(" System.out.println("1. Title e username: " + q1);
        } catch (NoPostIdException e) {
            System.out.println("1." + e.getMessage());
        }
        after = System.currentTimeMillis();
        logtime.writeLog("Query 1 -> " + (after - before) + " ms");
        log.writeLog("Query 1 -> " + q1);

        /*
           Query 2
        */
        before = System.currentTimeMillis();
        List<Long> q2 = qe.topMostActive(100);
        //System.out.println("2. Lista de Utilizadores com mais posts: " + q2);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 2 -> " + (after - before) + " ms");
        log.writeLog("Query 2 -> " + q2);

        /*
           Query 3
        */
        before = System.currentTimeMillis();
        Pair<Long, Long> q3 = qe.totalPosts(LocalDate.of(2016, Month.JULY, 1),
                LocalDate.of(2016, Month.JULY, 31));
        //System.out.println("3. Nº de perguntas e respostas: " + q3);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 3 -> " + (after - before) + " ms");
        log.writeLog("Query 3 -> " + q3);

        /*
           Query 4
        */
        before = System.currentTimeMillis();
        List<Long> q4 = qe.questionsWithTag("package-management", LocalDate.of(2013, Month.MARCH, 1),
                LocalDate.of(2013, Month.MARCH, 31));
        //System.out.println("4. IDS perguntas com tag: " + q4);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 4 -> " + (after - before) + " ms");
        log.writeLog("Query 4 -> " + q4);

        /*
           Query 5
        */
        before = System.currentTimeMillis();
        Pair<String, List<Long>>
                q5 = new Pair<>("", new ArrayList<>());
        try {
            q5 = qe.getUserInfo(15811);
            //System.out.println("5. informacoes Utilizador: " + q51);
        } catch (NoUserIdException e) {
            System.out.println("5. User não existe: " + e.getMessage());
        }

        after = System.currentTimeMillis();
        logtime.writeLog("Query 5 -> " + (after - before) + " ms");
        log.writeLog("Query 5 -> " + q5);

        /*
           Query 6
        */
        before = System.currentTimeMillis();
        List<Long> q6 = new ArrayList<>();
        int N6 = 5;
        try{
            q6 = qe.mostVotedAnswers(N6, LocalDate.of(2015, Month.NOVEMBER, 1),
                LocalDate.of(2015, Month.NOVEMBER,30));
            //System.out.println("6. IDS respostas com mais votos: " + q6);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("6. " + e.getMessage() + ": " + "não existem " + N6 + " respostas.");
        }
        after = System.currentTimeMillis();
        logtime.writeLog("Query 6 -> " + (after - before) + " ms");
        log.writeLog("Query 6 -> " + q6);

        /*
           Query 7
        */
        before = System.currentTimeMillis();
        List<Long> q7 = qe.mostAnsweredQuestions(10, LocalDate.of(2014,Month.AUGUST,1),
                LocalDate.of(2014,Month.AUGUST,11));
        //System.out.println("7. IDS perguntas com mais respostas: " + q7);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 7 -> "+(after-before)+" ms");
        log.writeLog("Query 7 -> "+q7);

        /*
           Query 8
        */
        before = System.currentTimeMillis();
        List<Long> q8 = qe.containsWord(10, "kde");
        //System.out.println("8. Contem palavra: " + q8);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 8 -> " + (after - before) + " ms");
        log.writeLog("Query 8 -> " + q8);

        /*
           Query 9
        */
        before = System.currentTimeMillis();
        List<Long> q9 = qe.bothParticipated(10, 87, 5691);
        //System.out.println("9. Both Participated: " + q9);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 9 -> " + (after - before) + " ms");
        log.writeLog("Query 9 -> " + q9);

        /*
           Query 10
        */
        before = System.currentTimeMillis();
        long q10 = -1;
        try{
            q10 = qe.betterAnswer(30334);
        } catch(NoQuestionIdException e) {
            System.out.println(e.getMessage());
        } catch (NoAnswersException e) {
            System.out.println(e.getMessage());
        }
        //System.out.println("10. Melhor Resposta: " + q10);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 10 -> "+(after-before)+" ms");
        log.writeLog("Query 10 -> "+q10);

        /*
            Query 11
        */
        before = System.currentTimeMillis();
        List<Long> q11 = new ArrayList<>();
        try{
            q11 = qe.mostUsedBestRep(5, LocalDate.of(2013,Month.NOVEMBER,01),
                  LocalDate.of(2013,Month.NOVEMBER,30));
        } catch(IllegalArgumentException e) {
            System.out.println("11. " + e.getMessage());
        } catch(IndexOutOfBoundsException e) {
            System.out.println("11. " + e.getMessage());
        }


        //System.out.println("11. IDS tags: " + q11);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 11 -> "+(after-before)+" ms");
        log.writeLog("Query 11 -> "+q11);

        /*
            CLEAN PHASE
         */
        before = System.currentTimeMillis();
        qe.clear();
        after = System.currentTimeMillis();
        logtime.writeLog("CLEAN -> "+(after-before)+" ms");

    }
}


