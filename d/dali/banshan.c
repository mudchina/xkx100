//Room: /d/dali/banshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","半山竹林");
	set("long",@LONG
一大片茂密的成年竹林生长在半山腰的缓坡上。竹子对大理地区
各民族来说是，既是重要的建筑材料，也是日常生活用品的原材料。
山下的村庄里的摆夷人经常上山来采伐竹子。北面山上有溪流下，到
这里水流已经颇大，山民经常把砍伐下的竹子丢在溪中，任其顺水飘
流，到村子附近的溪水里再捞起来。
LONG);
	set("objects", ([
	   __DIR__"npc/kanzhuren": 2,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : __DIR__"shanjian",
	    "east"     : __DIR__"buxiongbu",
	]));
	set("coor/x", -30970);
	set("coor/y", -70640);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}