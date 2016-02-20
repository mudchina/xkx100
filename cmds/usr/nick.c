// nick.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if( !arg ) return notify_fail("дЦр╙лФвт╪╨х║й╡ц╢╢б╨её©\n");
	if( arg == "none" ) 
	{
		me->delete("nickname");
		write("дЦ╣д╢б╨ех║оШак║ё\n");
		return 1;
	}
	if( !wizardp(me) && strlen(arg) > 30 )
		return notify_fail("дЦ╣д╢б╨ел╚Ё╓акё╛оКр╩╦Ж╤лр╩╣Ц╣д║╒оЛаар╩╣Ц╣д║ё\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("дЦх║╨цак╢б╨е║ё\n");
	return 1;
}
int help(object me)
{
	write(@HELP
ж╦аН╦Яй╫ : nick <мБ╨е, ╢б╨е> | none
 
    уБ╦Жж╦аН©иртхцдЦн╙вт╪╨х║р╩╦ЖоЛаа╣дцШ╨е╩Рм╥онё╛nick none
х║оШ╢б╨е║ёдЦхГ╧ШоёмШтз╢б╨ежпй╧сцansi╣д©ьжфвжт╙╦д╠Дяуи╚ё╛©ирт
сцртоб╣д©ьжфвж╢╝ё╨ё╗фДжпо╣мЁвт╤╞╩Атзвж╢╝н╡╤к╪ср╩╦Ж $NOR$ё╘

        $ёбёлёк$ё╨[30m╨зи╚[0m          
        $ёрёеёд$ё╨[31m╨Ли╚[0m          $ёхёиёр$ё╨[1;31mаа╨Ли╚[0m
        $ёгёрён$ё╨[32mбли╚[0m          $ёхёиёг$ё╨[1;32mаабли╚[0m
        $ёыёеёл$ё╨[33mма╩фи╚[0m        $ёхёиёы$ё╨[1;33m╩фи╚[0m
        $ёбёлёу$ё╨[34mиНю╤и╚[0m        $ёхёиёб$ё╨[1;34mю╤и╚[0m
        $ёмёаёг$ё╨[35mгЁвои╚[0m        $ёхёиём$ё╨[1;35m╥ш╨Ли╚[0m
        $ёцёыён$ё╨[36mю╤бли╚[0m        $ёхёиёц$ё╨[1;36mлЛгЮи╚[0m
        $ёвёхёт$ё╨[37mгЁ╩ри╚[0m        $ёхёиёв$ё╨[1;37m╟ви╚[0m
        $ёнёоёр$ё╨[0m╩ж╦╢уЩЁёяуи╚[0m

HELP
	);
	return 1;
}
