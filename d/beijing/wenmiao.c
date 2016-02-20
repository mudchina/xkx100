#include <room.h>
inherit ROOM;

void create()
{
	set("short", "文庙");
	set("long", @LONG
这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来
巩固自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭
毕敬地上香礼拜。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
