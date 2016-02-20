// Last Modified by Sir on May. 22 2001
//Room: byahoudian.c 白云庵后殿

inherit ROOM;
void do_chat();

void create()
{
	set("short","白云庵后殿");
	set("long",@LONG
恒山白云庵的后殿。是恒山派掌门人的居所。这里供有一尊普贤菩
萨像。两旁靠墙放着几张太师椅，地上放着几个蒲团。
LONG);
	set("no_clean_up", 0);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"changlang",	     
	]));
	set("coor/x", 40);
	set("coor/y", 3230);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
