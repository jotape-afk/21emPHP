<?php

$totalj = 0;
$totald = 0;
$baralho = ["A","2","3","4","5","6","7","8","9","10","J","Q","K",
            "A","2","3","4","5","6","7","8","9","10","J","Q","K",
            "A","2","3","4","5","6","7","8","9","10","J","Q","K",
            "A","2","3","4","5","6","7","8","9","10","J","Q","K"
            ];

shuffle($baralho);

//loop do jogador
do{
    echo("\n1 - Seguir" . PHP_EOL);
    echo("2 - Parar" . PHP_EOL);

    $perg = readline();
    $cartas = array_pop($baralho);

    if($perg == 1){

        if ($cartas == "J" || $cartas == "Q" || $cartas == "K") {
            $valor = 10;

        } elseif ($cartas == "A") {
            $valor = 11;

        } else {
            $valor = (int)$cartas;
        }

        $totalj += $valor;
        echo("PLAYER: " . $totalj . PHP_EOL);}

    elseif($perg == 2){
        echo("PLAYER: " . $totalj . PHP_EOL);
    }

    else{
        echo("Valor invalido" . PHP_EOL);
    }

}while($totalj < 21 && $perg != 2);

//loop dealer
do{
    $cartas = array_pop($baralho);

    if ($cartas == "J" || $cartas == "Q" || $cartas == "K") {
        $valor = 10;

    } elseif ($cartas == "A") {
        $valor = 11;

    } else {
        $valor = (int)$cartas;
    }

    $totald += $valor;

} while ($totald < $totalj && $totald <= 21);

if ($totalj > 21) {
    echo ("PLAYER perdeu");

} elseif ($totald > 21) {
    echo ("DEALER: " . $totald . PHP_EOL);
    echo ("PLAYER VENCEU!!!");

} elseif ($totalj == 21) {
    echo ("PLAYER VENCEU!!!");

} elseif ($totalj > $totald) {
    echo ("PLAYER VENCEU!!!");

} elseif ($totalj < $totald) {
    echo ("DEALER: " . $totald . PHP_EOL);
    echo ("PLAYER perdeu");
    
} else {
    echo ("EMPATE!");
}
?>