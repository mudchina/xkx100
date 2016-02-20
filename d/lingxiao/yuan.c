// Room: /d/lingxiao/yuan.c 渊侧 
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short", "分天渊侧");
	set("long", @LONG
过了分天崖，回头望望，白云寥寥，云气弥漫，想想还有点后怕，
但毕竟过来了。往前看，就是凌霄城了，这座武林中传说的名城，终于
出现在你面前了，赶快进去看看吧。
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
		"up"   : __DIR__"shanya",
		"down" : __DIR__"bingti",
	]));
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 135);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


