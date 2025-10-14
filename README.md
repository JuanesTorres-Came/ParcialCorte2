# 🛒 Administración de Pedidos para una Papelería

Este programa en **C** permite gestionar los pedidos de una papelería 📚.  
Se pueden registrar hasta **3 pedidos** con el nombre del cliente, productos, fecha y estado (pendiente o entregado).  
No se usan arreglos ni estructuras, solo variables simples.

---

## 🧠 Paso a Paso del Código

1. **📦 Declaración de variables**  
   Se crean variables individuales para cada pedido (cliente, productos, fecha y estado).  
   Ejemplo: `pedido1Cliente`, `pedido2Cliente`, `pedido3Cliente`.

2. **📝 Registro de pedidos**  
   Con la función `registrarPedido()` se guardan los datos del cliente, los productos, la fecha y el estado del pedido.  
   Solo se pueden registrar **3 pedidos** como máximo.

3. **🔍 Consulta de pedidos**  
   La función `consultarPedidos()` muestra todos los pedidos registrados.  
   También se puede buscar un pedido específico por el nombre del cliente.

4. **♻️ Actualización de estado**  
   Con `actualizarEstado()` se cambia el estado de un pedido (por ejemplo, de “pendiente” a “entregado”).

5. **📊 Generación de reporte**  
   La función `generarReporte()` cuenta cuántos pedidos están **entregados** y cuántos **pendientes**, mostrando un resumen final.

---

## 💡 En resumen

Este programa permite al encargado de una papelería:
- Registrar hasta tres pedidos  
- Consultarlos fácilmente  
- Actualizar su estado  
- Ver un reporte general  

Todo esto usando **solo variables primitivas en C** ✅
