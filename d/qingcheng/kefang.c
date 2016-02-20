// Room: /d/qingcheng/kefang.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这间整洁的厢房是给来青城做客、游玩的人们准备的房间，明净透
亮的窗户用厚厚的窗纱遮了大半。房里别无他物，只有中间放着一张收
拾得舒舒服服的大床，看着就让人想睡觉。青城弟子偶尔也来这里休息。
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3"
	]));
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}