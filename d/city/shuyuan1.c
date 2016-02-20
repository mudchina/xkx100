// Room: /d/city/shuyuan1.c
// Last Modified by winder on July. 20 2000
inherit ROOM;

void create()
{
	set("short", "至止堂");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。堂屋正中悬一幅青松图，
墨沉淋漓，未同凡响。两边挂一幅对联(lian)。西壁贴一孔子像，下一
红木方桌，左右各一红木雕花太师椅。一位庄重严肃的老者坐在太师椅
上讲学，那就是当今大儒朱先生了。在他的两侧坐满了求学的学生。一
张古意盎然的书案放在朱先生的前面，案上摆着几本翻开了的线装书籍。
讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在讲堂
前左壁的学规(xuegui)。书院老夫子刚奉了圣旨颁发学位，就在门口树
着书院新立的学位公告板(board)。楼上是飞雪堂，也是书院的书库。
LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"lian": @LONG

               花      读 
               鸟      书
               怡      养
               情      性
LONG,
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	求学需缴学费十两。\n",
		"board": "
       本书院奉圣上恩旨自即日起封授学位：
  0       文盲
 10       童生
 20       秀才
 30       举人
 40       解元
 50       贡士
 60       会元
 70       进士
 80       探花
 90       榜眼
100       状元
120       翰林院士
140       翰林硕士
160       翰林博士
180       翰林院编修
200       庶吉士
220       学士
240       内阁大学士
260       内阁首辅
280       文学大宗师
300       圣人\n" 
	]));
	set("exits", ([ /* sizeof() == 2 */
		"up"        : __DIR__"shuyuan2",
		"southdown" : __DIR__"shuyuan",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhu" : 1,
	]));
//	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_steal", 1);

	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}