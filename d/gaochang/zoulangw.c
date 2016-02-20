// Room: /d/gaochang/zoulangw.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
string look_writing();

void create()
{
	set("short", "въюх");
	set("long", @LONG
уБюОйг╣Нлцвъюх║ё╥©╤╔р╩╡Юж╖тздоцФ╣д╦ъг╫иоё╛аМр╩╡ЮтРсК╠╠╠ъ╣Н
лц╣днщ╤╔оЮа╛║ё╡йа╨╩╜╤╟ё╛л╖яшмШх╔ё╛а╛╤╔еОр╡сц╡йфА╩ФбЗак╦Вжж╥илЛ
╣дм╪пнё╛ц©╥Ы╩╜кф╨У╤╪тзкък╣р╩╦ЖФ╦Ф╦╤╞хк╣д╥П╬╜╧ййб║ёдо╠ъг╫иолБве
р╩╦Жвж(writing)║ё
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"wroom3",
		"northeast" : __DIR__"zoulangc",
	]));
	set("item_desc",([
		"writing"		:	(: look_writing :),
	]));
	set("no_clean_up", 0);
	setup();
}

string look_writing()
{
	return
	"\n"
"              оиоиоиоиоиоиоиоиоиоиоиоиоиоиоиоиои\n"
"              оиоиоиои  оиоиоиоиои    оиоиоиоиои\n"
"              оиоиоиои  оиоиоиоиои  оиоиоиоиоиои\n"
"              оиоиои    оиоиоиоиои  оиоиоиоиоиои\n"
"              оиои    оиоиоиоиоиои  оиоиоиоиоиои\n"
"              ои    ои  оиоиоиоиои  оиоиоиоиоиои\n"
"              оиоиоиои  оиои  оиои  оиоиои  оиои\n"
"              оиоиоиои  оиои  оиои  оиоиои  оиои\n"
"              оиоиоиои  оиои  оиои  оиоиои  оиои\n"
"              оиоиоиои  оиои  оиои  оиоиои  оиои\n"
"              оиоиоиои  оиои                оиои\n"
"              оиоиои    оиои  оиоиоиоиоиои  оиои\n"
"              оиоиоиоиоиоиоиоиоиоиоиоиоиоиоиоиои\n"
"              оиоиоиоиоиоиоиоиоиоиоиоиоиоиоиоиои\n";
}

void init()
{
	add_action("do_study", "yanxi");
}


int do_study(string arg)
{
	object me = this_player();
	int cost=10;	

	if ( !arg && ( arg != "qiang" ) && ( arg != "qiangbi" ) )
		return notify_fail("й╡ц╢ё©\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("дЦйг╦Жндц╓ё╛охя╖╣Цнд╩╞(literate)╟и║ё\n");

	if((int)me->query("jing") < 30)
		return notify_fail("дЦожтз╬╚иЯнч╥╗╪╞жпё║\n");

	me->receive_damage("jing", 10);

	message_vision("$NуЩв╗пдяп╤аг╫╠зио╣д╧е╧жм╪пн║ё\n", me);

	if ( (int)me->query_skill("medicine", 1) < 100)
	{
	      if ((int)me->query("jing")>cost)
		{me->improve_skill("medicine", (int)(me->query("int")/4));
		 write("дЦ╤твег╫╠звад╔акр╩╩ь╤Ыё╛кф╨У╤т╪цйюж╝йУсп╣Цпд╣ц║ё\n");
		 me->set_temp("stone_learned",1);
		 return 1;
		}
		else
	     {
		cost=me->query("jing");
		write("дЦожтз╧Щсзфё╬Кё╛нч╥╗в╗пдобю╢яп╤а╪цйюж╝йУ║ё\n");
	     } 
		 
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("дЦ╤твег╫╠звад╔акр╩╩ь╤Ыё╛╥╒ожиоцФкЫк╣╣дл╚╧ЩгЁотё╛╤тдЦю╢к╣ря╨анчрБрЕак║ё\n");
	}
	return 1;
}

