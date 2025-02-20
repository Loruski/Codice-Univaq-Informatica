# Link rapidi
[Tipi di valori](#tipi-di-valori)

[Assegnazione diretta](#li)

[Assegnazione registro](#move)

[Addizione](#add)

[Sottrazione](#sub)

[Divisione a due operandi](#div-due-operandi)

[Divisione a tre operandi](#div-tre-operandi)

[Moltiplicazione a due operandi](#mult-due-operandi)

[Moltiplicazione a tre operandi](#mul-tre-operandi)

[Assegnazione da hi](#mfhi)

[Assegnazione da lo](#mflo)

[Assegnazione di hi](#mthi)

[Assegnazione di lo](#mtlo)

# Introduzione
In MIPS i registri sono in due formati:
* `word` 32bit
* `half` 16bit

Possono essere visti come due gruppi da 16 bit, le due half formano una word
```
[0000000000000000][0000000000000000]
```

Gli operatori come addizione etc possono funzionare sia a 2 operatori che 3 operatori.

I register general purpose sono:
```assembly
a0,a1,a2,a3
t0,t1,t2,t3,t4,t5,t6,t7,t8,t9
s0,s1,s2,s3,s4,s5,s6,s7
```
Possono essere anche usati tramite solo il numero da `1-32`.

I registri vengono usati con il carattere $
> $s0, $1

Ci sono poi altri due registri specific purpose, usati nella divisone e moltiplicazione. Per esempio nella moltiplicazione viene usato per rappresentare il numero in 64 bit. Mentre per la divisione per salvare il risultato e il resto
```c
hi //higher
lo //lower
[hi][lo]
```

In tutti i comandi in MIPS, l'operando a sinistra è quello che **riceve** il dato, come in C
```assembly
li $s0, 100
;equivalente a: 
; s0 = 100
```


Mentre invece i numeri possono essere inseriti direttamente
```assembly
li $s3,826
```
# Tipi di valori
- **Immediato**, come un numero
- **Diretto-Registro**, il valore di un registro

# Comandi

## li
*Load Immediate*

Serve a settare il valore di un registro con un valore immediato (es: numerico), il primo sarà quello dove verrà settato il valore, il secondo, il valore da settare
```assembly
li <destinazione>, <numero>
li $s0, 100
; s0 = 100
```


## move
Serve a settare il valore di un registro con il valore di un altro registro. Il primo sarà il registro da settare, il secondo invece è dove verrà preso il valore
```assembly
move <destinazione>, <registro>
move $s0, $t0
; s0 = t0
```

## add
Somma il secondo e terzo operatore e mette il risultato nel primo

Solo il terzo operatore può essere un numero
```assembly
add <destinazione>, <registro>, <registro/numero>
add $s0, $t1, 100
; setta a s0 la somma di t1 + 100
; s0 = t1 + 100

add $s0, $t1, $t2
; setta a s0 la somma t1 + t2
; s0 = t1 + t2

NON VALIDO:
add $s0, 100, 200
```

## sub 
Fa la sottrazione
 tra secondo e terzo operando, mettendo il risultato nel primo

```assembly
sub <destinazione>, <registro>, <registro/numero> 

sub $s0, $t1, $t2
; s0 = t1 - t2

sub $s0, $t1, 100
; s0 = t1 - 100
```
**ATTENZIONE**
Il secondo operando deve **sempre** essere un registro, non può essere un numero:
```assembly
NON VALIDO:
sub $s1, 100, $t2
;s1 = 100 - $t2
```
Per fare questa cosa, dovremmo caricare il `100` in un registro
```assembly
li $t1, 100
sub $s1, $t1, $t2
; t1 = 100
; s1 = t1 - t2
```

## div (tre operandi)        
Effettua la divisione intera tra secondo operando (dividendo) e terzo operando (divisore) mettendo il risultato nel primo operando


**NOTA**: Il risultato viene calcolato esclusivamente in formato intero (NON ARROTONDATO), ciò significa che non viene restituito alcun tipo di resto da alcuna parte, né in `hi` né nello stesso registro di destinazione (come avviene su M68K), per avere il resto usare `div` [due operandi](#div-due-operandi)

```assembly
div <destinazione>, <registro>, <registro/numero>

div $a1, $t1, $t2
; a1 = t1 / t2

div $a1, $t1, 10
; a1 = t1 / 10
```


## div (due operandi)
Effettua la divisione intera tra il valore del primo operando (dividendo) e il valore del secondo (divisore), mettendo il risultato nei registri `hi` e `lo`.
    
in `lo` viene messo il quoziente, in `hi` il resto.

I registro `lo` e `hi` non possono essere letti direttamente ma vanno usati con i comandi [mflo](#mflo) e [mfhi](#mfhi)
    
**ATTENZIONE**
Il dividendo e divisore **DEVONO** essere dei registri
```assembly
div <dividendo>, <divisore>
    
div $s0, $t1 
; lo = s0 / t0
; hi = s0 % t0

mflo $s1 
; s1 = lo

mfhi $t1
; t1 = hi
```

## mul (tre operandi)
Effettua la moltiplicazione. Il risultato sarà salvato nel registro destinazione. 

**ATTENZIONE** Il risultato sarà espresso massimo in 32 bit, per la versione a 64 bit guarda [mult](#mult)

```assembly
mul <destinazione>, <registro>, <registro/numero>

mul $s0, $t0, $t1
; s0 = t0 * t1
mul $s0, $to, 100
; s0 = t0 * 100
```

## mult (due operandi)
Effettua la moltiplicazione tra due registri, salva le prime 32 cifre in `lo`, e le restanti 32 in `hi`
```assembly
mult <registro>,<registro>

mult $s0, $t0
; lo = primi 32 bit
; hi = ultimi 32 bit
```

## mfhi
*Move From `hi`*

Setta nel registro indicato il valore di `hi`
```assembly
mfhi <destinazione>

mfhi $s0
; s0 = hi
```


## mflo
*Move From `lo`*

Setta nel registro indicato il valore di `lo`
```assembly
mflo <destinazione>

mflo $s0
; s0 = lo
```


## mthi
*Move To `hi`*

Setta nel registro `hi` il valore del registro
```assembly
mthi <registro/numero>

mfhi $s0
;hi = s0
mfhi 50
;hi = 50
```

## mtlo
*Move To `lo`*

Setta nel registro `lo` il valore del registro
```assembly
mtlo <registro/numero>

mflo $s0
;lo = s0
mflo 50
;lo = 50
```