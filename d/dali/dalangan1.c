//Room: /d/dali/dalangan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","大杆栏");
	set("long",@LONG
依着一棵大榕树，摆夷人在此建了一座相当大的杆栏。下层这里
有一满圈的十几头牛羊。旁边的楼梯修得颇宽。看来这里是本地的体
面人家。
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 3,
	   __DIR__"npc/cow": 2,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"nongtian4",
	    "up"    : __DIR__"dalangan2",
	]));
	set("coor/x", -30940);
	set("coor/y", -70600);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}