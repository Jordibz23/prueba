/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import DTO.Datos;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;

/**
 *
 * @author Usuario
 */
public class datosDAO {

    public static EntityManagerFactory getEntity() {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("PruebaPU");
        return emf;
    }

    public static List<Datos> listar() {
        try {
            EntityManager em = getEntity().createEntityManager();
            Query q = em.createNamedQuery("Datos.findAll");
            List<Datos> dat = q.getResultList();
            return dat;
        } catch (Exception e) {
            return null;
        }
    }

    public static void agregar(Datos dat) {
        EntityManager em = getEntity().createEntityManager();
        em.getTransaction().begin();
        em.persist(dat);
        em.getTransaction().commit();
    }

    public static void main(String[] args) {
        List<Datos> list = datosDAO.listar();
        for (Datos dat : list) {
            System.out.println(dat.getUsuario()+" "+dat.getContraseña());
        }
    }
}
