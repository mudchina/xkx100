// Last Modified by Sir on May. 22 2001
//Room: changlang.c 长廊

inherit ROOM;
void do_chat();

void create()
{
	set("short","长廊");
	set("long",@LONG
通往恒山白云庵的后殿的一条长廊。往北便是是恒山派掌门人的居
所。南边是恒山派白云庵。
LONG);
	set("no_clean_up", 0);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"baiyunan", 
		"north" : __DIR__"byahoudian",
	]));
	set("coor/x", 40);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
