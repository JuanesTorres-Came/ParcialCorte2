# Variables para almacenar los pedidos (cada uno se maneja de forma independiente)
pedido1_cliente = ""
pedido1_productos = ""
pedido1_fecha = ""
pedido1_estado = ""

pedido2_cliente = ""
pedido2_productos = ""
pedido2_fecha = ""
pedido2_estado = ""

pedido3_cliente = ""
pedido3_productos = ""
pedido3_fecha = ""
pedido3_estado = ""

# Función para registrar un pedido
def registrar_pedido(numero_pedido, cliente, productos, fecha, estado):
    global pedido1_cliente, pedido1_productos, pedido1_fecha, pedido1_estado
    global pedido2_cliente, pedido2_productos, pedido2_fecha, pedido2_estado
    global pedido3_cliente, pedido3_productos, pedido3_fecha, pedido3_estado
    
    if numero_pedido == 1:
        pedido1_cliente = cliente
        pedido1_productos = productos
        pedido1_fecha = fecha
        pedido1_estado = estado
    elif numero_pedido == 2:
        pedido2_cliente = cliente
        pedido2_productos = productos
        pedido2_fecha = fecha
        pedido2_estado = estado
    elif numero_pedido == 3:
        pedido3_cliente = cliente
        pedido3_productos = productos
        pedido3_fecha = fecha
        pedido3_estado = estado
    else:
        print("Solo se pueden registrar hasta 3 pedidos.")

# Función para consultar un pedido o todos los pedidos
def consultar_pedido(cliente=None):
    if cliente:
        if pedido1_cliente == cliente:
            print(f"Pedido 1 - Cliente: {pedido1_cliente}, Productos: {pedido1_productos}, Fecha: {pedido1_fecha}, Estado: {pedido1_estado}")
        elif pedido2_cliente == cliente:
            print(f"Pedido 2 - Cliente: {pedido2_cliente}, Productos: {pedido2_productos}, Fecha: {pedido2_fecha}, Estado: {pedido2_estado}")
        elif pedido3_cliente == cliente:
            print(f"Pedido 3 - Cliente: {pedido3_cliente}, Productos: {pedido3_productos}, Fecha: {pedido3_fecha}, Estado: {pedido3_estado}")
        else:
            print(f"No se encontró un pedido para el cliente {cliente}.")
    else:
        if pedido1_cliente:
            print(f"Pedido 1 - Cliente: {pedido1_cliente}, Productos: {pedido1_productos}, Fecha: {pedido1_fecha}, Estado: {pedido1_estado}")
        if pedido2_cliente:
            print(f"Pedido 2 - Cliente: {pedido2_cliente}, Productos: {pedido2_productos}, Fecha: {pedido2_fecha}, Estado: {pedido2_estado}")
        if pedido3_cliente:
            print(f"Pedido 3 - Cliente: {pedido3_cliente}, Productos: {pedido3_productos}, Fecha: {pedido3_fecha}, Estado: {pedido3_estado}")

# Función para actualizar el estado de un pedido
def actualizar_estado(numero_pedido, nuevo_estado):
    global pedido1_estado, pedido2_estado, pedido3_estado
    if numero_pedido == 1:
        pedido1_estado = nuevo_estado
    elif numero_pedido == 2:
        pedido2_estado = nuevo_estado
    elif numero_pedido == 3:
        pedido3_estado = nuevo_estado
    else:
        print("Pedido no válido.")

# Función para generar el reporte de pedidos entregados y pendientes
def generar_reporte():
    entregados = 0
    pendientes = 0
    if pedido1_estado == "entregado":
        entregados += 1
    else:
        pendientes += 1

    if pedido2_estado == "entregado":
        entregados += 1
    else:
        pendientes += 1

    if pedido3_estado == "entregado":
        entregados += 1
    else:
        pendientes += 1

    print(f"Reporte de pedidos: \nEntregados: {entregados} \nPendientes: {pendientes}")

# Ejemplo de uso:

# Registrar pedidos
registrar_pedido(1, "Juan Pérez", "Cuaderno, Lápiz", "2025-10-01", "pendiente")
registrar_pedido(2, "Ana Gómez", "Borrador, Regla", "2025-10-02", "entregado")
registrar_pedido(3, "Carlos Díaz", "Papel, Pluma", "2025-10-03", "pendiente")

# Consultar todos los pedidos
print("Consulta de todos los pedidos:")
consultar_pedido()

# Consultar por cliente específico
print("\nConsulta por cliente (Ana Gómez):")
consultar_pedido("Ana Gómez")

# Actualizar estado de un pedido
print("\nActualizando estado del pedido 1 a 'entregado':")
actualizar_estado(1, "entregado")

# Generar reporte
print("\nGenerando reporte de pedidos:")
generar_reporte()
