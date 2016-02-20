// Room: /d/yanping/yidao3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽浙驿道");
	set("long", @LONG
这里是江边驿道。南面就是延平府城了。东边建溪中竹筏木排顺流
而下，在礁石险滩中穿行，浪涛汹涌，激起层层水雾，弥散两岸，与山
林芦苇相交集，人称“千古传名黯淡滩，十船经过九船翻”，那里便是
延平八景中的“黯淡洪涛”了。商人不知离别恨，桨橹击水、帆影摇风，
来往客商依旧匆匆。
LONG );
	set("exits", ([
		"northup"   : __DIR__"3800kan",
		"southeast" : __DIR__"fengguanyan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
