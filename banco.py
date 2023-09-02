#!/usr/bin/env python

import time
import os

logotipo = """
    /8888888  /8888888  /88   /88  /8888888  /8888888
   | 88  /88 | 88__/88 | 8888| 88 | 888___/ | 88__/88
   | 88888 / | 88  |88 | 88888888 | 888     | 88 | 88
   | 88  /88 | 8888888 | 88  8888 | 888     | 88 | 88
   | 8888888 | 88   88 | 88 \  88 | 8888888 | 8888888
   |/_____/  |/_/  /_/ |/_/  \/_/ |/_____/  |/_____/
"""

class Config:
    @staticmethod
    def logo():
        print(logotipo)

    @staticmethod
    def limpa():
        os.system("clear")

    @staticmethod
    def pausa(segundos):
        time.sleep(segundos)

def banco():
    config = Config()
    config.limpa()
    config.logo()
    config.pausa(1)

    menu = Menu(config, banco)  
    menu.escolha()

class Menu:
    def __init__(self, config, banco_func):
        self.config = config
        self.banco = banco_func  

    @staticmethod
    def info():
        espaco = " " * 20
        print(espaco, "{1}-> Conta.")
        print(espaco, "{2}-> Saldo.")
        print(espaco, "{3}-> Extrato.")
        opcao = input(":")
        return opcao

    def escolha(self):
        while True:
            opcao = self.info()
            if opcao == "1":
                self.config.limpa()
                self.config.logo()
                conta = [10]
                agencia  = [10]
                print(":agencia >")
                print(":conta > ")
                opcao = input(":")
                return
                
                if opcao == "conta"
                # parei aq
                    

            elif opcao == "2":
                print("\nExecutando a ação de Saldo.")
                time.sleep(1)

            elif opcao == "3":
                print("\nExecutando a ação de Extrato.")
                time.sleep(1)

            elif opcao == "r":
                self.banco()

            elif opcao == "q":
                self.config.limpa()
                print("bye!")
                break

            else:
                print("Entrada inválida. Tente novamente.")

if __name__ == "__main__":
    banco()
