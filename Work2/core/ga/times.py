import random
import time


fitness = []

number_of_individuals = int(input("Digite o numero desejado de individuos: "))
selected_individuals = int(input("Digite o numero de individuos selecionados: "))

start = time.time()

for i in range(number_of_individuals):
    fitness.append(random.uniform(0, 10))

def roleta(pesos, k):
    total = sum(pesos)
    escolhidos = []
    for i in range(k):
        r = random.uniform(0, total)
        acumulado = 0
        for j in range(len(pesos)):
            acumulado += pesos[j]
            if acumulado > r:
                escolhidos.append(j)
                break
    return escolhidos

roleta(fitness, selected_individuals)

end = time.time()
final = end - start

print("Total time spent: {}".format(final))