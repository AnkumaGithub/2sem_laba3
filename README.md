# 2sem_laba3
1) Memory_leak
   Цель: реализовать утечку памяти
   Утечка памяти: Каждый вызов new выделяет 400 байт (для int[100]), но delete[] отсутствует.
2) Unique_ptr
   Цель: Устранить утечки с помощью unique_ptr.
   Устранение утечек: unique_ptr автоматически удаляет объект при выходе из области видимости.
   RAII для файла: Файл закрывается в деструкторе класса File, даже если возникнет исключение.
3) Shared_ptr
   Цель: Демонстрация разделяемого владения ресурсом.
   Счётчик ссылок: Увеличивается при копировании shared_ptr.
   Уничтожение объекта: Происходит при use_count() == 0.
4) Weak_ptr
   Цель: Наблюдение за ресурсом без увеличения количества ссылок.
   weak_ptr не влияет на счётчик: Используется для безопасного наблюдения.
   .lock(): Создает временный shared_ptr для доступа к ресурсу.
   
Сравнение:  
Unique_ptr - Исключительное владение. Ресурс удаляется при выходе из области видимости.  
Shared_ptr - Разделяемое владение. Ресурс удаляется при use_count() == 0(отсутствие владения).  
Weak_ptr - Наблюдение без владения. Используется для предотвращения циклических ссылок.  
Ручное управление - крайне осторожно использовать.  

Рекомендации:  
Unique_ptr - Использовать по умолчанию для управления ресурсами.  
Shared_ptr - Применяйть только при необходимости разделяемого владения. Избегайть циклических ссылок с помощью weak_ptr.  
Weak_ptr - Использовать для наблюдения за объектами, время жизни которых контролируется shared_ptr.  
Ручное управление - не импользовать.  
