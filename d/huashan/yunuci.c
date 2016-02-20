// yunuci.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "玉女祠");
	set("long", @LONG
玉女祠里供奉的到底是哪位玉女，有许多不同的说法，现在所能看
到的只一尊呆板的石像。祠中大石上有一处深陷，凹处积水清碧，这是
玉女的洗脸盆，碧水终年不干。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"yunu",
	]));
	set("resource/water", 1);
	set("no_clean_up", 0);

	set("coor/x", -870);
	set("coor/y", 190);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
