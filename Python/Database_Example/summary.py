#Frazer Bayley 
#CIS 211
#Project #6 'summary.py'

"""
The program summary.py prints a customers monthly statement from Sakila DVD Rentals. 
The command line takes their last name, the year and month in question. And then prints
the list of all the movies they rented along with the date they were rented and the fee
associated with them. 
"""

from sys import argv    #gets all the commands from command line
script, last, year, month  = argv   #specifies command line prompts


import sqlite3   
from datetime import *
import decimal
con = sqlite3.connect('sakila211.db')  #establishes the sqlite cursor
cur = con.cursor()

"""
This sqlite query grabs the customers first name and last name as well as the films
title, rental date, rental rate, the return date and the amount of time the rental
has before its late. It takes an input of last name, year and month.
"""
cur.execute("""SELECT customer.first_name, customer.last_name,
            film.title, rental.rental_date, film.rental_rate, 
            rental.return_date, film.rental_duration
            FROM customer, rental, inventory, film 
            WHERE customer.last_name = ?
            AND rental.rental_date LIKE ?
            AND rental.rental_date LIKE ?
            AND customer.customer_id = rental.customer_id 
            AND rental.inventory_id = inventory.inventory_id
            AND inventory.film_id = film.film_id""", (last.title(), '{}-%'.format(year), 
            '%-{}-%'.format(month.zfill(2)),))


def main():
    """
    The main function carries out the entirety of the summary.py mechanics. It formats 
    the page as well as input the needed information from the tuple created by the sqlite 
    query.
    """
    print("--- Sakila DVD Rentals ---")
    print()
    counter = 0
    total = 0
    for first_name, last_name, title, rental_date, rental_rate, return_date, rental_duration in cur:
        if counter == 0:
            date_format = "%Y-%m-%d %H:%M:%S.%f"
            rented = datetime.strptime(rental_date, date_format)
            returned = datetime.strptime(return_date, date_format)
            diff = returned - rented
            print('Monthly report for {} {}'.format(first_name, last_name))
            print()
            print('{1:30}{0:%m}/{0:%d}/{0:%Y}{2:15}'.format(rented, title, rental_rate))
            late_fee = float(.99)
            if diff.days > rental_duration:
                print("               {:36}{}".format("**late fee", late_fee))
                total += late_fee
            else:
                pass
            counter += 1
            total += rental_rate
            
        else:
            date_format = "%Y-%m-%d %H:%M:%S.%f"
            rented = datetime.strptime(rental_date, date_format)
            returned = datetime.strptime(return_date, date_format)
            diff = returned - rented
            print('{1:30}{0:%m}/{0:%d}/{0:%Y}{2:15}'.format(rented, title, rental_rate))
            late_fee = float(.99)
            if diff.days > rental_duration:
                print("               {:36}{}".format("**late fee", late_fee))
                total += late_fee
            else:
                pass
            total += rental_rate
    
    dollar_amount = '{:4,.2f}'.format(total)
     
    print()
    print("Monthly total: ${}".format(dollar_amount))
               

if __name__ == '__main__':
    
    main()