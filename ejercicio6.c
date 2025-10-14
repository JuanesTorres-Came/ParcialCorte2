#include <stdio.h>
#include <string.h>

// ================================
// Sistema de Administración de Pedidos - Papelería
// ================================

// Variables globales para almacenar los pedidos (máximo 3)
char pedido1_cliente[50] = "";
char pedido1_productos[100] = "";
char pedido1_fecha[20] = "";
char pedido1_estado[20] = "";

char pedido2_cliente[50] = "";
char pedido2_productos[100] = "";
char pedido2_fecha[20] = "";
char pedido2_estado[20] = "";

char pedido3_cliente[50] = "";
char pedido3_productos[100] = "";
char pedido3_fecha[20] = "";
char pedido3_estado[20] = "";

// --------------------------------
// Función: Registrar un pedido
// --------------------------------
void registrar_pedido(int numero_pedido, char cliente[], char productos[], char fecha[], char estado[]) {
    if (numero_pedido == 1) {
        strcpy(pedido1_cliente, cliente);
        strcpy(pedido1_productos, productos);
        strcpy(pedido1_fecha, fecha);
        strcpy(pedido1_estado, estado);
    } 
    else if (numero_pedido == 2) {
        strcpy(pedido2_cliente, cliente);
        strcpy(pedido2_productos, productos);
        strcpy(pedido2_fecha, fecha);
        strcpy(pedido2_estado, estado);
    } 
    else if (numero_pedido == 3) {
        strcpy(pedido3_cliente, cliente);
        strcpy(pedido3_productos, productos);
        strcpy(pedido3_fecha, fecha);
        strcpy(pedido3_estado, estado);
    } 
    else {
        printf("Solo se pueden registrar hasta 3 pedidos.\n");
    }
}

// --------------------------------
// Función: Consultar pedidos
// --------------------------------
void consultar_pedido(char cliente[]) {
    int encontrado = 0;

    // Si el usuario no ingresa un cliente específico, mostramos todos
    if (strlen(cliente) == 0) {
        if (strlen(pedido1_cliente) > 0)
            printf("Pedido 1 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
                   pedido1_cliente, pedido1_productos, pedido1_fecha, pedido1_estado);

        if (strlen(pedido2_cliente) > 0)
            printf("Pedido 2 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
                   pedido2_cliente, pedido2_productos, pedido2_fecha, pedido2_estado);

        if (strlen(pedido3_cliente) > 0)
            printf("Pedido 3 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
                   pedido3_cliente, pedido3_productos, pedido3_fecha, pedido3_estado);

        return;
    }

    // Buscar por cliente
    if (strcmp(pedido1_cliente, cliente) == 0) {
        printf("Pedido 1 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
               pedido1_cliente, pedido1_productos, pedido1_fecha, pedido1_estado);
        encontrado = 1;
    }
    else if (strcmp(pedido2_cliente, cliente) == 0) {
        printf("Pedido 2 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
               pedido2_cliente, pedido2_productos, pedido2_fecha, pedido2_estado);
        encontrado = 1;
    }
    else if (strcmp(pedido3_cliente, cliente) == 0) {
        printf("Pedido 3 - Cliente: %s | Productos: %s | Fecha: %s | Estado: %s\n",
               pedido3_cliente, pedido3_productos, pedido3_fecha, pedido3_estado);
        encontrado = 1;
    }

    if (!encontrado) {
        printf("No se encontró un pedido para el cliente: %s\n", cliente);
    }
}

// --------------------------------
// Función: Actualizar estado de un pedido
// --------------------------------
void actualizar_estado(int numero_pedido, char nuevo_estado[]) {
    if (numero_pedido == 1 && strlen(pedido1_cliente) > 0) {
        strcpy(pedido1_estado, nuevo_estado);
    } 
    else if (numero_pedido == 2 && strlen(pedido2_cliente) > 0) {
        strcpy(pedido2_estado, nuevo_estado);
    } 
    else if (numero_pedido == 3 && strlen(pedido3_cliente) > 0) {
        strcpy(pedido3_estado, nuevo_estado);
    } 
    else {
        printf("Número de pedido inválido o pedido no registrado.\n");
    }
}

// --------------------------------
// Función: Generar reporte general
// --------------------------------
void generar_reporte() {
    int entregados = 0, pendientes = 0;

    if (strlen(pedido1_cliente) > 0) {
        if (strcmp(pedido1_estado, "entregado") == 0)
            entregados++;
        else
            pendientes++;
    }

    if (strlen(pedido2_cliente) > 0) {
        if (strcmp(pedido2_estado, "entregado") == 0)
            entregados++;
        else
            pendientes++;
    }

    if (strlen(pedido3_cliente) > 0) {
        if (strcmp(pedido3_estado, "entregado") == 0)
            entregados++;
        else
            pendientes++;
    }

    printf("\n📦 Reporte General de Pedidos:\n");
    printf("Pedidos entregados: %d\n", entregados);
    printf("Pedidos pendientes: %d\n", pendientes);
}

// --------------------------------
// Programa principal
// --------------------------------
int main() {
    printf("=== Sistema de Administración de Pedidos - Papelería ===\n\n");

    // Registrar pedidos de ejemplo
    registrar_pedido(1, "Juan Torres", "Cuaderno, Lápiz", "2025-10-01", "pendiente");
    registrar_pedido(2, "Heyder Ramos", "Borrador, Regla", "2025-10-02", "entregado");
    registrar_pedido(3, "Camilo Chaparro", "Papel, Marcador", "2025-10-03", "pendiente");

    printf("📋 Consulta de todos los pedidos:\n");
    consultar_pedido("");  // muestra todos

    printf("\n🔍 Consulta por cliente (Ana Gómez):\n");
    consultar_pedido("Ana Gómez");

    printf("\n🔄 Actualizando estado del pedido 1 a 'entregado'...\n");
    actualizar_estado(1, "entregado");

    printf("\n📊 Generando reporte final:\n");
    generar_reporte();

    return 0;
}
