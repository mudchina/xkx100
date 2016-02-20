// /cmds/skill/editskill.c
// Last modified by winder 2004.3.24
inherit F_CLEAN_UP;

#include <ansi.h>

#define SHUANGYIN_HAO "\""
string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
});
string *banned_name=({ "  ",});
mapping spe_skill = ([
	"action" : ({" "}),
	"damage" : ({"10"}),
	"dodge" : ({"10"}),
	"parry": ({"10"}),
	"damage_type" : ({"瘀伤"}),
	"lvl" : ({"10"}),
	"skill_name" : ({"横空出世"}),
	"skill_total_num" : ({"0"}),
	"skill_en_name" : ({" "}),
	"skill_ch_name" : ({" "}),
]);
int spe_skillnum;
string spe_skill_name;
string spe_skill_basename;
string spe_skill_help;
string oldfile;
//检查是否是3－12位的英文id
int check_legal_id(string id);
//检查是否是1－5个中文字
int check_legal_name(string name);
// 检查是否是允许的基本武功
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
// 提示用户输入当前招式中文名
void get_zhaoshi_ch_name(string yn, object ob);
// 提示用户输入当前招式描述
void get_zhaoshi_ch_action(string yn, object ob);
// 提示用户输入该武功的帮助文件
void get_skill_help(string yn,object ob);
// 检查玩家是否可以创建第skill_num招 返回skill_num
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
// 检查玩家是否可以改动skill_en_name这个文件
int check_owner_skill(object me,string skill_en_name);
// 从文件中读取这个武功的中文名
string get_header_skillchname(string file);
// 从文件中读取这个武功的基本武功名 
string get_header_skillbasename(string file);
int main(object me, string arg)
{
	int skill_num,skill_num_result;
	string skill_en_name,skill_ch_name,myskill;
	string skill_base_name;
	
	spe_skill_basename="";
	spe_skill_name="";
	spe_skill_help="";
	spe_skillnum=0;
	oldfile="";
	
	seteuid(getuid());
	if(!arg)
		return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第几招\n"NOR);
	if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
		return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第几招\n"NOR);
	skill_en_name=lower_case(skill_en_name);
	spe_skill_basename=skill_base_name;
	if(check_legal_basename(skill_base_name)==0)
		return notify_fail(RED"你输入的基本技能不存在。\n"NOR);
	if(check_legal_id(skill_en_name)==0)
		return 1;
	spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
	spe_skill_name=skill_en_name+"-"+skill_base_name;
	if(check_legal_name(skill_ch_name)==0) return 1;             
	spe_skill["skill_ch_name"]=skill_ch_name;
	if( skill_num!=1 && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
		return notify_fail( HIR"你输入的中文武功名称和所选的英文武功代号有矛盾。\n"NOR);
	if( skill_num!=1 && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
		return notify_fail( HIR"你输入的基本技能名和所选的英文武功代号有矛盾。\n"NOR);
	if(mapp(me->query("skillmaxim")) &&
		sizeof(me->query("skillmaxim")) >3 )
		return notify_fail(HIR"你最多只能自创三种武功。\n"NOR);
	switch(check_owner_skill(me,spe_skill["skill_en_name"]))
	{
		case 2:
			return notify_fail( HIR"此功夫已存在，无法创新。\n"NOR);
			break;
		case 0: 
			break;
		case 1:
			return notify_fail( HIR"你目前只能针对这个基本技能创建一个功夫。\n"NOR);
		default:
			return notify_fail( HIR"所创功夫不对，请看帮助。\n"NOR);
	}
	if(skill_num < 1)
		return notify_fail(HIR"你需要从第一招开始创建。\n"NOR);
	if((int)me->query("combat_exp") < (skill_num)*1000000+9000000)
		return notify_fail(HIR"你的经验还不够，不能自创武功了。\n"NOR);
	if((int)me->query("score") < 20000)
		return notify_fail(HIR"你的江湖阅历还不够，不能自创武功了。\n"NOR);
	if(//(int)me->query_skill(spe_skill_name,1)!=0  &&
		(int)me->query_skill(spe_skill_name,1) < (skill_num-1)*20)
		return notify_fail( HIR"你的招式还不够熟练，先提高一下，然后在想新招吧。\n"NOR);
	spe_skillnum=skill_num;
	skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));
	if (file_size(SKILL_D(spe_skill["skill_en_name"])))
		oldfile = read_file(SKILL_D(spe_skill["skill_en_name"]));
	switch(skill_num_result)
	{
		case -1 :
			//无法取得已经创的招式总数
			return notify_fail(HIR"你的所要创建的武功有错，请通知巫师解决。\n"NOR);
		case 0 :
			return notify_fail( HIR"你只能创建新招或者修改最近创建的招式，请重新尝试。\n"NOR);
		case 1 :
			// 如果创或改第一招的话 那么一切重来
//			rm(SKILL_D(spe_skill["skill_en_name"]));
			skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
			write( HIG"你现在开始创建"+skill_ch_name+"("+spe_skill_name+")"HIG"。\n"NOR);
			write( HIW"给这个武功写一个简介，以后会在帮助文档中体现，换行用$代替。\n"NOR);
			input_to( (: get_skill_help :) ,this_player());
			return 1;
		default:
		//如果在原有招式上增加新的招式
			write(HIW"\r给招式起个名字（不要此时断线，否则永远无法再正确创建）："NOR);
			input_to( (: get_zhaoshi_ch_name :), this_player() );
			return 1;
	}
	return 0;
}
void get_skill_help(string yn,object ob)
{
	if (yn=="")
	{
		write( HIW"给这个武功写一个简介，将会在帮助文档中体现。\n"NOR);
		write( HIW"换行可以用$代替\n"NOR);
		input_to( (:get_skill_help:) ,ob);
		return;
	}
	spe_skill_help = "\n\t"+yn;
	write(HIW"\r给招式起个名字（不要此时断线，否则永远无法再正确创建）："NOR);
	input_to( (: get_zhaoshi_ch_name :), this_player() );
	return;
}
string get_header_skillchname(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 8) return 0;
	else
	{
		if(sscanf(list[7],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
string get_header_skillbasename(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 7) return 0;
	else
	{
		if(sscanf(list[6],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
void skill_init_header(string skill_en_name,string skill_ch_name)
{
	string header, result;
	object me = this_player();
	int i;
	string str;

	result="";
	header="";

	header="// 这是玩家自创武功程序。\n";		//list[0]
	header+="// "+geteuid(me)+"\n";			//list[1]
	header+="// "+me->query("name")+"\n";		//list[2]
	header+="// "+me->query("title")+"\n";		//list[3]
	header+="// "+me->query("combat_exp")+"\n";	//list[4]
	header+="// "+me->query("gender")+"\n";		//list[5]
	header+="// "+spe_skill_basename+"\n";		//list[6]
	header+="// "+spe_skill["skill_ch_name"]+"\n";	//list[7]
	header+="#include <ansi.h>\n";
	header+="inherit SKILL;\n";			
	header+="string type() { return \"martial\"; }\n";
	header+="string martialtype() { return \"skill\"; }\n";
	header+="string owner() {return \""+geteuid(me)+"\";}\n";
	header+="\nmapping *action = ({\n});\n";		
	header+="// ZHAOSHI :0";			//注意：最后没有用\n
	write_file(SKILL_D(skill_en_name),header,1);
}
void get_zhaoshi_ch_name(string yn, object ob)
{
	if( yn=="" )
	{
		write(HIW"\r请给招式起个名字（不要此时断线，否则永远无法在正确创建）："NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	if( !check_legal_name(yn) )
	{
		write(HIW"\r请给招式起个名字（不要此时断线，否则永远无法在正确创建）："NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	spe_skill["skill_name"]=yn;
	write(WHT"\n想象一下你和某人的战斗，指南：必须要有["+HIR+"你、某人、某部位"NOR+WHT"]的字样出现！");
	write("\n如果是sword或blade请加入["HIR"武器"NOR+WHT"]字样。以下是举例。");
	write( HIG"\n拳法示例："NOR+WHT"你前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向某人的某部位\n");
	write( HIG"武器类例："NOR+WHT"你纵身一跃，手中武器一招「金光泻地」对准的某部位斜斜刺出一剑\n"NOR);
	input_to( (: get_zhaoshi_ch_action :), ob);
}
void get_zhaoshi_ch_action(string yn, object ob)
{
	string err;
	string file;

	if( yn=="" )
	{
		write(WHT"\n想象一下你和某人的战斗，指南：最好要有["+HIR+"你、某人、某部位"NOR+WHT"]的字样出现!");
		write( "\n如果是sword或blade请加入["HIR"武器"NOR+WHT"]字样。以下是举例。");
		write( HIG"\n拳法示例："NOR+WHT"你前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向某人的某部位\n");
		write( HIG"武器类例："NOR+WHT"你纵身一跃，手中武器一招「金光泻地」对准的某部位斜斜刺出一剑\n"NOR);
		input_to( (: get_zhaoshi_ch_action :), ob );
		return;
	}
	spe_skill["action"]=yn;
	finish_write_skill(ob);
	if(spe_skillnum==1)
	{
		ob->set("skillmaxim/"+spe_skill_basename,spe_skill_name);
		ob->set_skill(spe_skill_name,1);
		ob->add("score",-20000);
		CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);
	}
	log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n", ob->query("name"), ob->query("id"), spe_skill["skill_ch_name"], spe_skill_name, spe_skillnum, ctime(time()) ) );
	file = SKILL_D(spe_skill["skill_en_name"]);
	if (file_size(file))
	{
		if (find_object(file)) destruct(find_object(file));
		err = catch(call_other(file,"???"));
		if (stringp(err))
		{
			log_file("CREATESKILL","失败，错误描述："+err);
			message("channel:sys",HIR"【系统】自创武功编辑出错。\n"NOR,users());
			write("创建武功失败，请联系当值巫师解决。\n");
			if (stringp(oldfile))
			{
				write_file(file,oldfile,1);
				call_other(file,"???");
			}
		}
	}
}
void finish_write_skill(object ob)
{
	string action, file, *list, content, *list2, header2, result;
	int before_skillnum,i;
	int flag,x,y;
	int d_e1,d_e2;//dodge上下限
	int p_e1,p_e2;//parry上下限
	int f_e1,f_e2;//force上下限
	int m_e1,m_e2;//damage上下限
	object me = this_player();

	header2="";
	result="";
	content="";
	action="";
	spe_skill["lvl"]  =20 * (spe_skillnum-1);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLK$", BLK);
	spe_skill["action"]= replace_string(spe_skill["action"],"$RED$", RED);
	spe_skill["action"]= replace_string(spe_skill["action"],"$GRN$", GRN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$YEL$", YEL);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLU$", BLU);
	spe_skill["action"]= replace_string(spe_skill["action"],"$MAG$", MAG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$CYN$", CYN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$WHT$", WHT);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIR$", HIR);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIG$", HIG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIY$", HIY);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIB$", HIB);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIM$", HIM);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIC$", HIC);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIW$", HIW);
	spe_skill["action"]= replace_string(spe_skill["action"],"$NOR$", NOR);
	spe_skill["action"]= replace_string(spe_skill["action"],"\"", "");
	spe_skill["action"]= replace_string(spe_skill["action"],"$","\n");
	spe_skill["action"]= replace_string(spe_skill["action"],"你","$N");
	spe_skill["action"]= replace_string(spe_skill["action"],"某人","$n");
	spe_skill["action"]= replace_string(spe_skill["action"],"某部位","$l");
	spe_skill["action"]= replace_string(spe_skill["action"],"武器","$w");
	spe_skill["action"] += NOR;
	action  = "\n([\n";
	action += "\t"+SHUANGYIN_HAO+"action"+SHUANGYIN_HAO+" : "
	        + SHUANGYIN_HAO+spe_skill["action"]+SHUANGYIN_HAO
	        + ",\n";
	action += "\t"+SHUANGYIN_HAO+"lvl"+SHUANGYIN_HAO+" : "
		+ spe_skill["lvl"]+",\n";
	action += "\t"+SHUANGYIN_HAO+"skill_name"+SHUANGYIN_HAO+" : "
		+ SHUANGYIN_HAO + spe_skill["skill_name"] + SHUANGYIN_HAO
		+ ",\n";
	action += "]),\n";
	action += "});\n";
	action += "// ZHAOSHI :"+spe_skillnum;


	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if ((int)file==0)
	{
		write(HIR"可能出现异常了，请联系巫师解决。\n"NOR);
		return;
	}
	list = explode(file, "\n");
// 帮助文档
	for(i=0;i<sizeof(list);i++)
	{
		if (list[i]=="	write\(\@HELP")	x=i;
		if (list[i]=="HELP")		y=i;
	}
	if (!stringp(spe_skill_help))
	{
		if (intp(x) && intp(y))
		spe_skill_help = implode(list[x+1..y-1],"\n");
		else
		spe_skill_help = this_player()->query("name")+"的自创武功。\n";
	}
	spe_skill_help = replace_string(spe_skill_help,"\"","");
	spe_skill_help = replace_string(spe_skill_help,"$","\n");
// 帮助文档结束
/*
参考
string *spe_skill_lvl=({ "0","12","20","30","40","50","60","80","100",});
string *spe_skill_force=({ "50","80","100","130","150","180","200","220", });
string *spe_skill_unarmeddodge=({ "10","-10","-20","-30","-50","-60","-80","-90","-100", });
string *spe_skill_unarmedparry=({ "10","-10","-20","-30","-40","-50","-60","-70","-80", });
string *spe_skill_weapondodge=({ "20","10","10","5","-5","-5","-10","-10","-10", });
string *spe_skill_weaponparry=({ "20","20","10","10","5","5","5","5","5", });
*/
	if(spe_skill_basename=="unarmed")
	{
		header2=read_file(SKILL_MODEL_UNARMED);
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 50 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 50 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 0;
		m_e2 = 0;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
	}
	else
	{
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 10 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 10 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 50 + me->query("str")*3 + 6*spe_skillnum;
		m_e2 = 50 + me->query_str()*3  + 6*spe_skillnum;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
		if(spe_skill_basename=="sword" || spe_skill_basename=="blade")
			header2=read_file(SKILL_MODEL_WEAPON);
		else header2=read_file(SKILL_MODEL_DEFAULT);
	}

	list2 = explode(header2, "\n");
	for(i=0;i < sizeof(list2);i++)
	{
		list2[i]= replace_string(list2[i], "SKILL_EN_NAME", 
			SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_CH_NAME", 
			SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_BASE_NAME", 
			SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_HELP",
			spe_skill_help);
		list2[i]= replace_string(list2[i], "D_E1",sprintf("%d",d_e1));
		list2[i]= replace_string(list2[i], "D_E2",sprintf("%d",d_e2));
		list2[i]= replace_string(list2[i], "P_E1",sprintf("%d",p_e1));
		list2[i]= replace_string(list2[i], "P_E2",sprintf("%d",p_e2));
		list2[i]= replace_string(list2[i], "F_E1",sprintf("%d",f_e1));
		list2[i]= replace_string(list2[i], "F_E2",sprintf("%d",f_e2));
		list2[i]= replace_string(list2[i], "M_E1",sprintf("%d",m_e1));
		list2[i]= replace_string(list2[i], "M_E2",sprintf("%d",m_e2));
	}
	result += implode(list2,"\n");
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",before_skillnum)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		write(HIR"可能出现异常了，请看帮助解决。\n"NOR);
		return;
	}
	if( before_skillnum==spe_skillnum)
	{
		flag = 0;
		for(i=i-6;i>0;i--)
		{
			if (sscanf(list[i],"// ZHAOSHI :%*d")==1)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			write(HIR"可能出现异常情况了，请联系巫师解决。\n"NOR);
			return;
		}
		content = implode(list[0..i],"\n");
		content += action;
		write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	else
	{
			content = implode(list[0..i-2],"\n");
			content+="\n// ZHAOSHI :"+(string)before_skillnum;
			content+=action;
			write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
}
int check_legal_basename(string name)
{
	int i;
	for(i=0;i<sizeof(valid_types);i++) 
		if(valid_types[i]==name) return 1;
	return 0;
}
int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if( (strlen(id) < 3) || (strlen(id) > 12 ) )
	{
		write("你的武功代号必须是 3 到 12 个英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' )
		{
			write("你的武功代号只能用英文字母。\n");
			return 0;
		}
        return 1;
}
int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 12 ) )
	{
		write("武功的中文名称必须是 1 到 6 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("你的武功中文名城不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("你的武功中文名要用「中文」!\n");
			return 0;
		}
	}
	if( member_array(name,banned_name)!=-1 )
	{
		write("你的武功中文名称会造成其他人的困扰。\n");
		return 0;
	}
	return 1;
}
int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
	string file,*list;
	string playername;
	int total_zhaoshi_num;
	int flag,i;

	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0) return 0;
		else return 1;
	}
	else list = explode(file, "\n");

	playername=geteuid(me);
	if(list[0]!="// 这是玩家自创武功程序。")
		return 0;
	if(list[1]!="// "+playername)
		return 0;
//	if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
//		return 0;
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",total_zhaoshi_num)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag) return -1;
	if(total_zhaoshi_num==0) return 0;
	if(total_zhaoshi_num==skill_num) return skill_num;
	if(total_zhaoshi_num+1 == skill_num) return skill_num;
	return 0;
}
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else 
			return 0;
	}
	else list = explode(file, "\n");
	playername=geteuid(me);
	if(list[1]!="// "+playername) return 2;
	if(list[0]!="// 这是玩家自创武功程序。") return 2;
	else return 0;
}

int help (object me)
{
	write(@HELP
指令格式：editskill 武功基本技能 武功英文名字 武功中文名字 第几招
例如：editskill unarmed jueqin 绝情拳 1 
 
    这是用来创建自己风格武功的指令，随着经验值的增长，可以实现的招式
越来越多，招式的威力也越来越大。每创造一种武功，必须要有两万点江湖阅
历。
    玩家增加招式的熟练程度的方式是使用个专用指令：
    mylian，用practice也可以，但是难度会加大。

    由于是自己摸索招式，所以难度要大些。玩家只能修改当前的招式，对以
前的招式无法改动。所以玩家要事先规划好总共要创几招，边练边修改，以免
到时侯无法改动以前的基本招式。

    可以利用的基本功夫有：
	unarmed,
	sword,
	blade,
注意:
    招式的英文名称后面将被加上基本技能的几个标识，玩家要事先想好，一
旦开始创建则无法随意改动英文名称，如上例将会得到名为jueqin-unarmed的
一项武功。招式描述中不要加入控制字符。玩家最多只能创建三种高级功夫。
    招式描述中的：
    某人，你，某部位，武器带有普遍性，将来可以用来对付各种不同敌人。

    招式的描述不要带有对自己或对手状态的描写，不要不负责的乱写。巫师
将检查玩家所创建的功夫，如不符合规定，将被删除。
HELP);
	return 1;
}
