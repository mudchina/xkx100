// Room: /d/huangshan/diezhang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "叠嶂峰");
	set("long", @LONG
山峰实在是多，相传黄山三千六百峰，从叠嶂峰来看，只怕尤有过
之，仅次一处山峰便难以计算，群峰叠嶂，都是一根而出，看似群峰，
也难说清究竟该有多少，过去是极难行走，好在现在以有石阶，铁索，
游人便可以轻松到达后山的松谷庵。
LONG
	);
	set("exits", ([ 
		"southeast" : __DIR__"qingliang",
		"north"     : __DIR__"songgu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
