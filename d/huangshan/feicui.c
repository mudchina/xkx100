// Room: /d/huangshan/feicui.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "翡翠池");
	set("long", @LONG
在松谷溪边，星罗棋布着六个池潭。平时潭水清澈平静，每当微风
吹动，涟漪微荡，好似龙鳞，所以叫龙潭。依照水色分为赤，青，乌，
白，老，更有一潭，水深形美，所以被称为翡翠池。四周石桌，石栏，
悬崖题刻，应有尽有，别有风味。据说闻名天下的龙化剑便是依此五潭
悟出，也不知真假。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"songgu",
	]));
	set("objects", ([
		__DIR__"obj/pond1" : 1,
		__DIR__"obj/pond2" : 1,
		__DIR__"obj/pond3" : 1,
		__DIR__"obj/pond4" : 1,
		__DIR__"obj/pond5" : 1,
		__DIR__"obj/pond6" : 1,
	]) );

	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
