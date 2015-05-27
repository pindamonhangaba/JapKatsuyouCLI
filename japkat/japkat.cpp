#include "japkat.h"
#include "edict2.h"
#include "msg.h"
#include "typeDefs.h"
#include "jpconj.h"
#include <QDebug>

JapKat::JapKat(QObject *parent) :
    QObject(parent)
{
}

void JapKat::doConj(QString verb)
{
    Edict2 edict2;

    EdictType type = edict2.find(verb);
    QString result = "";
    if (type < 1){
        result = "{\"error\":\"not a verb/no conjugation\"}";
    }

    QString complex = complexConjugation(verb, type);
    QString basic = basicConjugation(verb, type);
    result = "{\"complex\":" + complex + ",\"basic\":" + basic + "}";

    QTextStream _stdout(stdout);
    _stdout.setCodec("UTF-8");
    _stdout << result;
    _stdout.flush();
}

/*!
 * \brief jpconjmain::basicConjugation Used to show the standard and basic conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
QString JapKat::basicConjugation(QString verb, EdictType type)
{
    QMap<KForm, QString> basicForms = Msg::basicFormsMap();
    QString result = "[";
    foreach (KForm form, basicForms.keys()){
        result += "{\""+getKForm(form)+"\":\"";
        result += JpConj::Katsuyou(verb, type, form);
        result += "\"},";
    }
    result.chop(1);
    result += "]";
    return result;
}

/*!
 * \brief jpconjmain::complexConjugation Used to show the complex conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
QString JapKat::complexConjugation(QString verb, EdictType type)
{
    QMap<CForm, QString> complexForms = Msg::complexFormsMap();
    QString result = "[";
    foreach (CForm form, complexForms.keys()){
        result += "{\""+getCForm(form)+"\":{";
        result += "\"Polite\":{\"Affirmative\":\"";
        result += JpConj::Conjugate(verb, type, form, _Polite, _Affirmative)+"\",\"Negative\":\"";
        result += JpConj::Conjugate(verb, type, form, _Polite, _Negative)+"\"";
        result += "},\"Plain\":{\"Affirmative\":\"";
        result += JpConj::Conjugate(verb, type, form, _Plain, _Affirmative)+"\",\"Negative\":\"";
        result += JpConj::Conjugate(verb, type, form, _Plain, _Negative)+"\"";
        result += "}}},";
    }
    result.chop(1);
    result += "]";
    return result;
}

QString JapKat::getCForm(enum CForm cform)
{
    switch (cform) {
    case _TeForm:
        return "TeForm";
        break;
    case _Present:
        return "Present";
        break;
    case _Past:
        return "Past";
        break;
    case _Provision:
        return "Provision";
        break;
    case _Condition:
        return "Condition";
        break;
    case _Imperative:
        return "Imperative";
        break;
    case _Volitional:
        return "Volitional";
        break;
    case _PresentContinuous:
        return "PresentContinuous";
        break;
    case _PastContinuous:
        return "PastContinuous";
        break;
    case _Causative:
        return "Causative";
        break;
    case _CausativePassive:
        return "CausativePassive";
        break;
    case _Potential:
        return "Potential";
        break;
    /*case _Desire:
        return "";
        break;
    case _WhileDoing:
        return "";
        break;
    case _WayOfDoing:
        return "";
        break;*/
    default:
        return "";
        break;
    }
}

QString JapKat::getKForm(KForm kform, bool desc) {
    switch (kform) {
    case _Imperfective_a:
        return desc ? "Imperfective (general)|未然形" : "Imperfective_a";
        break;
    case _Imperfective_o:
        return desc ? "Imperfective (volutional)|未然形" : "Imperfective_o";
        break;
    case _Conjunctive_i:
        return desc ? "Conjunctive (-i)|連用形" : "Conjunctive_i";
        break;
    case _Conjunctive_t:
        return desc ? "Conjunctive (other)|連用形" : "Conjunctive_t";
        break;
    case _Terminal_u:
        return desc ? "Attributive|終止形" : "Terminal_u";
        break;
    case _Attributive_u:
        return desc ? "Attributive|連体形" : "Attributive_u";
        break;
    case _Hypothetical_e:
        return desc ? "Hypothetical|仮定形" : "Hypothetical_e";
        break;
    case _Imperative_e:
        return desc ? "Imperative|命令形" : "Imperative_e";
        break;
    default:
        return "";
        break;
    }
}
