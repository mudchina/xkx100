// Room: /d/wuyi/tianyouguan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天游观");
	set("long", @LONG
天游峰的天游观，始建天床，明嘉靖五年重建，有殿宇式的楼阁，
名「遨游霄汉」，成为游客饮茶，赏景的场所，阁后有妙高台、振衣岗
、红豆树诸胜。古人云：「飞泉响落睛疑雨，古木浓荫夏亦寒」。
    观中供奉着彭祖的两个儿子：彭武和彭夷。相传二人疏浚三三水，
堆就六六峰，才有了这座碧水丹山的人间洞天。山因之名。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"down"    : __DIR__"tianyoufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

