// Room: /d/lingxiao/feihua.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","飞花阁");
	set("long",@LONG 
这是凌霄城长门第六代弟子，「寒梅女侠」花万紫的居所，楼名飞
花阁。花万紫是凌霄城六代弟子中唯一的女性，一来为避嫌，二来花万
紫本就性喜清净，故一人独居于此。此处是花园小楼之上，凭窗而望，
千万朵梅花迎雪飞舞，万梅飘零，纷纷而下。桌上放着一束五颜六色的
梅花。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"down"  : __DIR__"huajing",  
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/hua" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

