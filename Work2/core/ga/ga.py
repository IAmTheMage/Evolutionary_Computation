import ctypes
import pathlib
from typing import List
import random
import time


if __name__ == "__main__":
    libname = pathlib.Path().absolute() / "libcore.so"
    c_lib = ctypes.CDLL(libname)
    
c_lib.roulette.restype = ctypes.POINTER(ctypes.c_int)


fitness = []

number_of_individuals = int(input("Digite o numero desejado de individuos: "))
selected_individuals = int(input("Digite o numero de individuos selecionados: "))

start = time.time()

for i in range(number_of_individuals):
    fitness.append(random.uniform(0, 10))
    
_converted_fitness = (ctypes.c_double * len(fitness))(*fitness)

resp = c_lib.roulette(_converted_fitness, number_of_individuals, selected_individuals)

resp_casted = ctypes.cast(resp, ctypes.POINTER(ctypes.c_int))
    
end = time.time()
final = end - start

print("Total time spent: {}".format(final))