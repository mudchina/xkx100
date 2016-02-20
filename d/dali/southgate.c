//Room: /d/dali/southgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","南门");
	set("long",@LONG
此间是大理国都大理城的南门，大理城实名阳苜咩城，南诏于初
建来，经历代而至当今的段氏的“大理国”，皆以此城为都。城墙由
石块和土垒成，高二丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪
大了眼睛观察着来来往往的行人，偶尔盘问几个形迹可疑份子。
LONG);
	set("objects", ([
	   __DIR__"npc/jiang": 1,
	   __DIR__"npc/bing": 3,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"shizilukou",
	    "east"       : __DIR__"xiaodao2",
	    "south"      : __DIR__"shuangheqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40000);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}