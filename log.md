
ft_printf:
    ft_printf:
        main called function

parsing:
    get_str_lit:
        gets the string literal of the mods and specifiers
    get_width:
        gets the width specifier
    parse_mods:
        gets each mod and puts it in an array
    get_spec:
        gets the specifer
    main_write:
        calls each get and then puts the data into a stuct to be sent to a write function

struct stuff:
    create_ele:
        mallocs the dataspace for the t_specvar type
    del_var:
        frees the dataspace from a t_specvar

test main:
    main:
        just a test function

variable param
    this is a blanked file. I rewrote the functions in it.

errors:
    invalid_mods:
        exit case for invalid mods
    double_mod:
        exit case for double mods

switches:
    var_param_read:
        determines what the variable paramiters are supposed to be
    write_calls:
        calls the desired write function.

debugging:
    print_mods:
        prints out the mods and what they corralate too

write_data_type & 2 & more:
    Basically all the same functions, but slightly different. Writes the data in the specified format.
    I really don't feel like writing out each specific one, they're really self explanitory

misc:
    addneg:
        supporting function for itoa
    ft_ltoa:
        itoa adapted for long ints
    point_to_str:
        itoa but for pointers